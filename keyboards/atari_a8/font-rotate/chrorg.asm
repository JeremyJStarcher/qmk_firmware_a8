	.INCLUDE	"camac.inc"
;	SUBTTL	'Domestic Character Set'
;	SPACE	4,10
	.SEGMENT "CHRORG"
	ORG	$E000
;	SPACE	4,10
;**	Domestic Character Set


	DB	$00,$00,$00,$00,$00,$00,$00,$00	;$00 - space
	DB	$00,$18,$18,$18,$18,$00,$18,$00	;$01 - !
	DB	$00,$66,$66,$66,$00,$00,$00,$00	;$02 - "
	DB	$00,$66,$FF,$66,$66,$FF,$66,$00	;$03 - #
	DB	$18,$3E,$60,$3C,$06,$7C,$18,$00	;$04 - $
	DB	$00,$66,$6C,$18,$30,$66,$46,$00	;$05 - %
	DB	$1C,$36,$1C,$38,$6F,$66,$3B,$00	;$06 - &
	DB	$00,$18,$18,$18,$00,$00,$00,$00	;$07 - '
	DB	$00,$0E,$1C,$18,$18,$1C,$0E,$00	;$08 - (
	DB	$00,$70,$38,$18,$18,$38,$70,$00	;$09 - )
	DB	$00,$66,$3C,$FF,$3C,$66,$00,$00	;$0A - asterisk
	DB	$00,$18,$18,$7E,$18,$18,$00,$00	;$0B - plus
	DB	$00,$00,$00,$00,$00,$18,$18,$30	;$0C - comma
	DB	$00,$00,$00,$7E,$00,$00,$00,$00	;$0D - minus
	DB	$00,$00,$00,$00,$00,$18,$18,$00	;$0E - period
	DB	$00,$06,$0C,$18,$30,$60,$40,$00	;$0F - /

	DB	$00,$3C,$66,$6E,$76,$66,$3C,$00	;$10 - 0
	DB	$00,$18,$38,$18,$18,$18,$7E,$00	;$11 - 1
	DB	$00,$3C,$66,$0C,$18,$30,$7E,$00	;$12 - 2
	DB	$00,$7E,$0C,$18,$0C,$66,$3C,$00	;$13 - 3
	DB	$00,$0C,$1C,$3C,$6C,$7E,$0C,$00	;$14 - 4
	DB	$00,$7E,$60,$7C,$06,$66,$3C,$00	;$15 - 5
	DB	$00,$3C,$60,$7C,$66,$66,$3C,$00	;$16 - 6
	DB	$00,$7E,$06,$0C,$18,$30,$30,$00	;$17 - 7
	DB	$00,$3C,$66,$3C,$66,$66,$3C,$00	;$18 - 8
	DB	$00,$3C,$66,$3E,$06,$0C,$38,$00	;$19 - 9
	DB	$00,$00,$18,$18,$00,$18,$18,$00	;$1A - colon
	DB	$00,$00,$18,$18,$00,$18,$18,$30	;$1B - semicolon
	DB	$06,$0C,$18,$30,$18,$0C,$06,$00	;$1C - <
	DB	$00,$00,$7E,$00,$00,$7E,$00,$00	;$1D - =
	DB	$60,$30,$18,$0C,$18,$30,$60,$00	;$1E - >
	DB	$00,$3C,$66,$0C,$18,$00,$18,$00	;$1F - ?

	DB	$00,$3C,$66,$6E,$6E,$60,$3E,$00	;$20 - @
	DB	$00,$18,$3C,$66,$66,$7E,$66,$00	;$21 - A
	DB	$00,$7C,$66,$7C,$66,$66,$7C,$00	;$22 - B
	DB	$00,$3C,$66,$60,$60,$66,$3C,$00	;$23 - C
	DB	$00,$78,$6C,$66,$66,$6C,$78,$00	;$24 - D
	DB	$00,$7E,$60,$7C,$60,$60,$7E,$00	;$25 - E
	DB	$00,$7E,$60,$7C,$60,$60,$60,$00	;$26 - F
	DB	$00,$3E,$60,$60,$6E,$66,$3E,$00	;$27 - G
	DB	$00,$66,$66,$7E,$66,$66,$66,$00	;$28 - H
	DB	$00,$7E,$18,$18,$18,$18,$7E,$00	;$29 - I
	DB	$00,$06,$06,$06,$06,$66,$3C,$00	;$2A - J
	DB	$00,$66,$6C,$78,$78,$6C,$66,$00	;$2B - K
	DB	$00,$60,$60,$60,$60,$60,$7E,$00	;$2C - L
	DB	$00,$63,$77,$7F,$6B,$63,$63,$00	;$2D - M
	DB	$00,$66,$76,$7E,$7E,$6E,$66,$00	;$2E - N
	DB	$00,$3C,$66,$66,$66,$66,$3C,$00	;$2F - O

	DB	$00,$7C,$66,$66,$7C,$60,$60,$00	;$30 - P
	DB	$00,$3C,$66,$66,$66,$6C,$36,$00	;$31 - Q
	DB	$00,$7C,$66,$66,$7C,$6C,$66,$00	;$32 - R
	DB	$00,$3C,$60,$3C,$06,$06,$3C,$00	;$33 - S
	DB	$00,$7E,$18,$18,$18,$18,$18,$00	;$34 - T
	DB	$00,$66,$66,$66,$66,$66,$7E,$00	;$35 - U
	DB	$00,$66,$66,$66,$66,$3C,$18,$00	;$36 - V
	DB	$00,$63,$63,$6B,$7F,$77,$63,$00	;$37 - W
	DB	$00,$66,$66,$3C,$3C,$66,$66,$00	;$38 - X
	DB	$00,$66,$66,$3C,$18,$18,$18,$00	;$39 - Y
	DB	$00,$7E,$0C,$18,$30,$60,$7E,$00	;$3A - Z
	DB	$00,$1E,$18,$18,$18,$18,$1E,$00	;$3B - [
	DB	$00,$40,$60,$30,$18,$0C,$06,$00	;$3C - \
	DB	$00,$78,$18,$18,$18,$18,$78,$00	;$3D - ]
	DB	$00,$08,$1C,$36,$63,$00,$00,$00	;$3E - ^
	DB	$00,$00,$00,$00,$00,$00,$FF,$00	;$3F - underline

	DB	$00,$36,$7F,$7F,$3E,$1C,$08,$00	;$40 - heart card
	DB	$18,$18,$18,$1F,$1F,$18,$18,$18	;$41 - mid left window
	DB	$03,$03,$03,$03,$03,$03,$03,$03	;$42 - right box
	DB	$18,$18,$18,$F8,$F8,$00,$00,$00	;$43 - low right window
	DB	$18,$18,$18,$F8,$F8,$18,$18,$18	;$44 - mid right window
	DB	$00,$00,$00,$F8,$F8,$18,$18,$18	;$45 - up right window
	DB	$03,$07,$0E,$1C,$38,$70,$E0,$C0	;$46 - right slant box
	DB	$C0,$E0,$70,$38,$1C,$0E,$07,$03	;$47 - left slant box
	DB	$01,$03,$07,$0F,$1F,$3F,$7F,$FF	;$48 - right slant solid
	DB	$00,$00,$00,$00,$0F,$0F,$0F,$0F	;$49 - low right solid
	DB	$80,$C0,$E0,$F0,$F8,$FC,$FE,$FF	;$4A - left slant solid
	DB	$0F,$0F,$0F,$0F,$00,$00,$00,$00	;$4B - up right solid
	DB	$F0,$F0,$F0,$F0,$00,$00,$00,$00	;$4C - up left solid
	DB	$FF,$FF,$00,$00,$00,$00,$00,$00	;$4D - top box
	DB	$00,$00,$00,$00,$00,$00,$FF,$FF	;$4E - bottom box
	DB	$00,$00,$00,$00,$F0,$F0,$F0,$F0	;$4F - low left solid

	DB	$00,$1C,$1C,$77,$77,$08,$1C,$00	;$50 - club card
	DB	$00,$00,$00,$1F,$1F,$18,$18,$18	;$51 - up left window
	DB	$00,$00,$00,$FF,$FF,$00,$00,$00	;$52 - mid box
	DB	$18,$18,$18,$FF,$FF,$18,$18,$18	;$53 - mid window
	DB	$00,$00,$3C,$7E,$7E,$7E,$3C,$00	;$54 - solid circle
	DB	$00,$00,$00,$00,$FF,$FF,$FF,$FF	;$55 - bottom solid
	DB	$C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0	;$56 - left box
	DB	$00,$00,$00,$FF,$FF,$18,$18,$18	;$57 - up mid window
	DB	$18,$18,$18,$FF,$FF,$00,$00,$00	;$58 - low mid window
	DB	$F0,$F0,$F0,$F0,$F0,$F0,$F0,$F0	;$59 - left solid
	DB	$18,$18,$18,$1F,$1F,$00,$00,$00	;$5A - low left window
	DB	$78,$60,$78,$60,$7E,$18,$1E,$00	;$5B - display escape
	DB	$00,$18,$3C,$7E,$18,$18,$18,$00	;$5C - up arrow
	DB	$00,$18,$18,$18,$7E,$3C,$18,$00	;$5D - down arrow
	DB	$00,$18,$30,$7E,$30,$18,$00,$00	;$5E - left arrow
	DB	$00,$18,$0C,$7E,$0C,$18,$00,$00	;$5F - right arrow

	DB	$00,$18,$3C,$7E,$7E,$3C,$18,$00	;$60 - diamond card
	DB	$00,$00,$3C,$06,$3E,$66,$3E,$00	;$61 - a
	DB	$00,$60,$60,$7C,$66,$66,$7C,$00	;$62 - b
	DB	$00,$00,$3C,$60,$60,$60,$3C,$00	;$63 - c
	DB	$00,$06,$06,$3E,$66,$66,$3E,$00	;$64 - d
	DB	$00,$00,$3C,$66,$7E,$60,$3C,$00	;$65 - e
	DB	$00,$0E,$18,$3E,$18,$18,$18,$00	;$66 - f
	DB	$00,$00,$3E,$66,$66,$3E,$06,$7C	;$67 - g
	DB	$00,$60,$60,$7C,$66,$66,$66,$00	;$68 - h
	DB	$00,$18,$00,$38,$18,$18,$3C,$00	;$69 - i
	DB	$00,$06,$00,$06,$06,$06,$06,$3C	;$6A - j
	DB	$00,$60,$60,$6C,$78,$6C,$66,$00	;$6B - k
	DB	$00,$38,$18,$18,$18,$18,$3C,$00	;$6C - l
	DB	$00,$00,$66,$7F,$7F,$6B,$63,$00	;$6D - m
	DB	$00,$00,$7C,$66,$66,$66,$66,$00	;$6E - n
	DB	$00,$00,$3C,$66,$66,$66,$3C,$00	;$6F - o

	DB	$00,$00,$7C,$66,$66,$7C,$60,$60	;$70 - p
	DB	$00,$00,$3E,$66,$66,$3E,$06,$06	;$71 - q
	DB	$00,$00,$7C,$66,$60,$60,$60,$00	;$72 - r
	DB	$00,$00,$3E,$60,$3C,$06,$7C,$00	;$73 - s
	DB	$00,$18,$7E,$18,$18,$18,$0E,$00	;$74 - t
	DB	$00,$00,$66,$66,$66,$66,$3E,$00	;$75 - u
	DB	$00,$00,$66,$66,$66,$3C,$18,$00	;$76 - v
	DB	$00,$00,$63,$6B,$7F,$3E,$36,$00	;$77 - w
	DB	$00,$00,$66,$3C,$18,$3C,$66,$00	;$78 - x
	DB	$00,$00,$66,$66,$66,$3E,$0C,$78	;$79 - y
	DB	$00,$00,$7E,$0C,$18,$30,$7E,$00	;$7A - z
	DB	$00,$18,$3C,$7E,$7E,$18,$3C,$00	;$7B - spade card
	DB	$18,$18,$18,$18,$18,$18,$18,$18	;$7C - |
	DB	$00,$7E,$78,$7C,$6E,$66,$06,$00	;$7D - display clear
	DB	$08,$18,$38,$78,$38,$18,$08,$00	;$7E - display backspace
	DB	$10,$18,$1C,$1E,$1C,$18,$10,$00	;$7F - display tab
