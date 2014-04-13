	AREA FindZ, CODE, READONLY
	ENTRY
			
	MOV r0, #2
	MOV r1, #2
	MOV r2, #2
	MOV r3, #2
	MOV r4, #2
	
	MUL R6, r3, r4
	ADD r0, r0, r1
	ADD r0, r0, r2
	SUB r0, r0, r6
	
	MOV r5, r0
	
	END