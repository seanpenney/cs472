		AREA palindrome, CODE, READONLY
		ENTRY
							
start	LDR r1, =string_begin		
		LDR r2, =string_end
		BL pal				
stop

pal		LDRB r3, [r1], #1	; get left hand character
		LDRB r4, [r2], #-1	; get right hand character
		CMP r3, r4			; compare the ends of the string
		BNE notpal			; if different then fail
		SUBS r3, r2, r1		; get difference between pointers
		BEQ waspal			; if same then exit with palindrome found
		BMI waspal			; if left pointer past right then palindrome
		B pal				; REPEAT
waspal	MOV r0, #0x1		; r0 = 1 = success flag
		MOV pc, lr			; return
notpal	MOV r0, #0x0		; r0 = 0 = fail flag
		MOV pc, lr			; return
		
		END