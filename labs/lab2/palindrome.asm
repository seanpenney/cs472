		AREA palindrome, CODE, READONLY
		ENTRY
			
start	LDR r0, =string		; r0 points to start of string to test
		MOV r1, r0			; copy left pointer to right pointer in r1
loop	LDRB r10, [r1], #1	; get character and update right pointer
		CMP r10, #0			; repeat until terminator located
		BNE loop
		SUB r1, r1, #2		; fix right pointer to point to end of string
		BL pal				; call subroutine to test for palindrome
stop

pal		LDRB r3, [r0], #1	; get left hand character
		LDRB r4, [r1], #-1	; get right hand character
		CMP r3, r4			; compare the ends of the string
		BNE notpal			; if different then fail
		SUBS r3, r1, r0		; get difference between pointers
		BEQ waspal			; if same then exit with palindrome found
		BMI waspal			; if left pointer past right then palindrome
		B pal				; REPEAT
waspal	MOV r10, #0x1		; r10 = 1 = success flag
notpal	MOV pc, lr			; return

	AREA palindrome, DATA, READWRITE
string	DCB "pots",0		; string to test
	
		END