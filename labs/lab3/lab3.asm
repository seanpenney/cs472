; Sean Penney and Paul Atkinson, Lab 3
		AREA lab3, CODE, READONLY
		ENTRY

MAIN	MOV r13, #0xA000	; initialize stack pointer
		; initialize values for the SWAP subroutine
		MOV r1, #1
		MOV r2, #2
		MOV r3, #3
		MOV r4, #4
		MOV r5, #5
		MOV r6, #6
		MOV r7, #7
		BL SWAP				; call subroutine for problem 3.57
		MOV r0, #3			; setup r0 for next subroutine
		BL MATH				; call subroutine for problem 3.59
		BL VECTOR			; call subroutine for problem 3.60
		BL ENDIAN			; call subroutine for last part of lab
		B END

SWAP	STMIA r13!, {r1-r7} ; block store
		MOV r13, #0xA000
		LDMIA r13!, {r3, r4, r5, r6, r7}	; block load
		LDMIA r13!, {r1, r2}	; block load
		MOV pc, lr			; Return from subroutine

MATH	PUSH {r1-r9}		; store registers
		
		ADR r7, VALA		; get addresss of VALA
		ADR r8, VALB		; get address of VALB
		ADR r9, VALC		; get address of VALC
		
		LDR r1, [r7]		; get value at VALA
		LDR r2, [r8]		; get value at VALB
		LDR r3, [r9]		; get value at VALC
		
		MUL r4, r0, r2		; r4 = bx
		MUL r5, r0, r0		; r5 = x^2
		MUL r6, r5, r3		; r6 = cx^2
		ADD r5, r4, r6		; r5 = bx + cx^2
		ADD r0, r5, r1		; r0 = a + bx + cx^2
		
		POP {r1-r9}			; restore values of registers
		MOV pc, lr			; Return from subroutine
		
VECTOR	MOV r0, #8			; loop 8 times
		ADR r1, VECA
		ADR r2, VECB
		ADR r3, VECC
LOOP	LDR r4, [r1], #4	; get element from VECA, post increment address
		LDR r5, [r2], #4	; get element from VECB, post increment address
		ADD r6, r4, r5		; add elements from VECA and VECB
		LSR r6, r6, #1		; shift result to right (divide by 2)
		STR r6, [r3], #4	; store result in VECC and post increment address
		SUBS r0, r0, #1		; decrement loop counter and set status flag
		BNE LOOP			; continue untsil loop counter is 0
		MOV pc, lr			; Return from subroutine

ENDIAN	MRS r0, CPSR		; load Program Status Register into r0
		AND r0, #0x00000100	; check bit 9 (for endianness)
		
		; Flip endianness of value in r0, using r1 as temp register
		EOR r1, r0, r0, ROR #16
		BIC r1, r1, #0x00FF0000
		MOV r0, r0, ROR #8
		EOR r0, r0, r1, LSR #8
		MOV pc, lr			; Return from subroutine

END		B END			; End of program
			
		AREA lab3, DATA, READWRITE
VALA	DCD 2			; Constant for 2nd subroutine
VALB	DCD 3			; Constant for 2nd subroutine
VALC	DCD 4			; Constant for 2nd subroutine
VECA	DCD 1,2,3,4,5,6,7,8 ; 8 element vector
VECB	DCD 1,2,3,4,5,6,7,8 ; 8 element vector
VECC	DCD 0,0,0,0,0,0,0,0 ; 8 element vector
		END