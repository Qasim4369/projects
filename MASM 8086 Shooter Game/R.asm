;i201783_i202652_i211728;
;Qasim Shafiq, Talha Tariq, Ruwaid Ahmed;
include a1.lib
.model small
.stack 100h
.data
username1 db 100 dup('$')
entername db 'ENTER USER NAME : $'
title1 db  '|***** WELCOME *****|','$'
title2 db 'TO:','$'
title3 db 'Brick Breaker','$'
dev1 db 'Qasim Shafiq','$'
dev2 db 'Ruwaid Ahmed','$'
dev3 db 'Talha Tariq','$'


	rules db 'HOW TO PLAY!','$'
	lineabove db    '--------','$'
	start_button db '\| PLAY |/','$'
	quit db '!! QUIT BUTTON !!$'
	howto db 'HOW TO PLAY:','$'
	skip_to_level2 db 'Skip To L2$'
	not_skip_to_level2 db 'NOT Skip To L2$'
	skip_to_level3 db 'Skip To L3$'
	not_skip_to_level3 db 'NOT Skip To L3$'
	rule1 db '1. Use keyboard keys (right and left)to move','$'
	rule2 db '2. Press enter key to shoot','$'
	rule3 db '3. You have 3 lives .','$'
	rule4 db '4. The score will be recorded when the block will explode.','$'
		level1 db 'LEVEL 1','$'
	level2 db 'LEVEL 2 ','$'
	level3 db 'LEVEL 3','$'
		clickonthescreen db 'CLICK ON THE SCREEN$'
	writeyourname db 'Write Your Name: $'
	filename db 'file2_1.txt',0
	buffer dw 50 dup(?)
	counter dw 0
	fhandle dw 0
	
	dia dw ?; diagonal 2 var
	x dw 80
	y dw 140
	x1 dw 0
	y1 dw 0
	x2 dw 0
	y2 dw 0
	loop_var1 db 0
	loop_var2 db 0
	x3 dw 10
	y3 dw 10
	str1 db "SCORE: $"
	score dw 0
	tempx dw 0
	arr1 dw 20 dup(?)
	arr2 dw 20 dup(?)
	x4 dw 0
	y4 dw 0
	decisionx db 0
	decisiony db 0
	loop_var3 db 0
	bullet_stop db 0
	enemies_pos dw 70
	loop_var4 db 0
	loop_var5 db 0
	Page_Number db 0
	columns db 10
	Rows db 0
	
	x5 dw 80
	y5 dw 140
	x6 dw 5
	y6 dw 5
	x7 dw 0
	y7 dw 0
	x8 dw 5
	y8 dw 5
	x9 dw 0
	y9 dw 0
	loop_var6 db 0
	loop_var7 db 0
	loop_var8 db 0
	loop_var9 db 0
	cond_var1 db 5
	cond_var2 db 4
	score_1 dw 0
	str2 db "Score: $"
	stop_enemies dw 80
	enemies_pos_1 dw 65
	arr3 dw 20 dup(?)
	arr4 dw 20 dup(?)
	decisionx_1 db 0
	decisiony_1 db 0
.code
main proc
MOV AX,@DATA
MOV DS,AX
DISPLAY:

;Screen Selection
mov AH,00h
mov AL,12h ;640 x 480
mov bh,00h
int 10h
display_start1
;call DISPLAY
;;;;;;;;;;;;;;TURNING PLAY INTO A BUTTON;;;;;;;;;;;;;;;;;;;;;;;
mov ax,01
int 33h
.repeat
	mov ax,05
	int 33h	
	.if bx==0 && cx<=600 && cx>=500 && dx<=300 && dx>=200
		change_background 0,0,0,30,80,00001110b ;clear_screen,upper_row_num,left_column_num,lower_row_num,right_column_num,color    
		position_cursor 0,5,2 ;PG_NUM,colnum,rows
		string_print howto
		position_cursor 0,19,5 ;PG_NUM,colnum,rows
		string_print rule1
		position_cursor 0,19,10 ;PG_NUM,colnum,rows
		string_print rule2
		position_cursor 0,19,15 ;PG_NUM,colnum,rows
		string_print rule3
		position_cursor 0,19,20 ;PG_NUM,colnum,rows
		string_print rule4
		
		position_cursor 0,19,25 ;PG_NUM,colnum,rows
		string_print quit
		
		quitit:
			mov ax,05
			int 33h
			cmp bx,0
			jne quitit
			cmp cx,400
			jnle quitit
			cmp cx,200
			jnge quitit
			cmp dx,400
			jnge quitit
			cmp dx,480
			jnle quitit
		skip:
		jmp DISPLAY
	.endif
.until bx==0 && cx<=600 && cx>=500 && dx<=480 && dx>=300
MOV AH,00h; Selecting Video Mode
MOV AL,13 ; Selecting Resolution:320x200 256 color graphics (MCGA,VGA)
INT 10h; Selecting Inerupt for Graphics mode
; Setting for Background Color
mov dx,offset str1
mov ah,09
int 21h
mov ah,0Bh
mov bh,01h; fix setting for background color
mov bl,00h; choose color Blue color
int 10h
mov si,0
mov bp,0
push x3
push y3
.repeat
finish:
pop bx
position_cursor_1 Page_Number, columns,Rows
