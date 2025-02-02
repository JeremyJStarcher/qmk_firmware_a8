
def getit(n):
    empty = [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]


    ch = chr(n)

    if n == 3:
      return [0x00,0x36,0x7F,0x7F,0x3E,0x1C,0x08,0x00]  #0x40 - heart card

    if n == 4:
      return [0x00,0x18,0x3C,0x7E,0x7E,0x3C,0x18,0x00]  #0x60 - diamond card
    if n == 5:
      return [0x00,0x18,0x3C,0x7E,0x7E,0x18,0x3C,0x00]  #0x7B - spade card
    if n == 6:
      return [0x00,0x1C,0x1C,0x77,0x77,0x08,0x1C,0x00]  #0x50 - club card



    if ch == 24:
      return [0x00,0x18,0x3C,0x7E,0x18,0x18,0x18,0x00]  #0x5C - up arrow
    if ch == 25:
      return [0x00,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00]  #0x5D - down arrow
    if ch == 26:
      return [0x00,0x18,0x0C,0x7E,0x0C,0x18,0x00,0x00]  #0x5F - right arrow
    if ch == 27:
      return [0x00,0x18,0x30,0x7E,0x30,0x18,0x00,0x00]  #0x5E - left arrow


    if ch == ' ':
      return [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]  #0x00 - space


    if ch == '!':
      return [0x00,0x18,0x18,0x18,0x18,0x00,0x18,0x00]  #0x01 - !
    if ch == '"':
      return [0x00,0x66,0x66,0x66,0x00,0x00,0x00,0x00]  #0x02 - DQUOTE
    if ch == '#':
      return [0x00,0x66,0xFF,0x66,0x66,0xFF,0x66,0x00]  #0x03 - #
    if ch == "$":
      return [0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00]  #0x04 - $
    if ch == "%":
      return [0x00,0x66,0x6C,0x18,0x30,0x66,0x46,0x00]  #0x05 - %
    if ch == "&":
      return [0x1C,0x36,0x1C,0x38,0x6F,0x66,0x3B,0x00]  #0x06 - &
    if ch == "'":
      return [0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00]  #0x07 - '
    if ch == "(":
      return [0x00,0x0E,0x1C,0x18,0x18,0x1C,0x0E,0x00]  #0x08 - (
    if ch == ")":
      return [0x00,0x70,0x38,0x18,0x18,0x38,0x70,0x00]  #0x09 - )
    if ch == "*":
      return [0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00]  #0x0A - asterisk
    if ch == "+":
      return [0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00]  #0x0B - plus
    if ch == ",":
      return [0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30]  #0x0C - comma
    if ch == "-":
      return [0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00]  #0x0D - minus
    if ch == ".":
      return [0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00]  #0x0E - period
    if ch == "/":
      return [0x00,0x06,0x0C,0x18,0x30,0x60,0x40,0x00]  #0x0F - /

    if ch == "0":
      return [0x00,0x3C,0x66,0x6E,0x76,0x66,0x3C,0x00]  #0x10 - 0
    if ch == "1":
      return [0x00,0x18,0x38,0x18,0x18,0x18,0x7E,0x00]  #0x11 - 1
    if ch == "2":
      return [0x00,0x3C,0x66,0x0C,0x18,0x30,0x7E,0x00]  #0x12 - 2
    if ch == "3":
      return [0x00,0x7E,0x0C,0x18,0x0C,0x66,0x3C,0x00]  #0x13 - 3
    if ch == "4":
      return [0x00,0x0C,0x1C,0x3C,0x6C,0x7E,0x0C,0x00]  #0x14 - 4
    if ch == "5":
      return [0x00,0x7E,0x60,0x7C,0x06,0x66,0x3C,0x00]  #0x15 - 5
    if ch == "6":
      return [0x00,0x3C,0x60,0x7C,0x66,0x66,0x3C,0x00]  #0x16 - 6
    if ch == "7":
      return [0x00,0x7E,0x06,0x0C,0x18,0x30,0x30,0x00]  #0x17 - 7
    if ch == "8":
      return [0x00,0x3C,0x66,0x3C,0x66,0x66,0x3C,0x00]  #0x18 - 8
    if ch == "9":
      return [0x00,0x3C,0x66,0x3E,0x06,0x0C,0x38,0x00]  #0x19 - 9
    if ch == ":":
      return [0x00,0x00,0x18,0x18,0x00,0x18,0x18,0x00]  #0x1A - colon
    if ch == ";":
      return [0x00,0x00,0x18,0x18,0x00,0x18,0x18,0x30]  #0x1B - semicolon
    if ch == "<":
      return [0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00]  #0x1C - <
    if ch == "=":
      return [0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00]  #0x1D - =
    if ch == ">":
      return [0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00]  #0x1E - >
    if ch == "?":
      return [0x00,0x3C,0x66,0x0C,0x18,0x00,0x18,0x00]  #0x1F - ?

    if ch == "@":
      return [0x00,0x3C,0x66,0x6E,0x6E,0x60,0x3E,0x00]  #0x20 - @
    if ch == "A":
      return [0x00,0x18,0x3C,0x66,0x66,0x7E,0x66,0x00]  #0x21 - A
    if ch == "B":
      return [0x00,0x7C,0x66,0x7C,0x66,0x66,0x7C,0x00]  #0x22 - B
    if ch == "C":
      return [0x00,0x3C,0x66,0x60,0x60,0x66,0x3C,0x00]  #0x23 - C
    if ch == "D":
      return [0x00,0x78,0x6C,0x66,0x66,0x6C,0x78,0x00]  #0x24 - D
    if ch == "E":
      return [0x00,0x7E,0x60,0x7C,0x60,0x60,0x7E,0x00]  #0x25 - E
    if ch == "F":
      return [0x00,0x7E,0x60,0x7C,0x60,0x60,0x60,0x00]  #0x26 - F
    if ch == "G":
      return [0x00,0x3E,0x60,0x60,0x6E,0x66,0x3E,0x00]  #0x27 - G
    if ch == "H":
      return [0x00,0x66,0x66,0x7E,0x66,0x66,0x66,0x00]  #0x28 - H
    if ch == "I":
      return [0x00,0x7E,0x18,0x18,0x18,0x18,0x7E,0x00]  #0x29 - I
    if ch == "J":
      return [0x00,0x06,0x06,0x06,0x06,0x66,0x3C,0x00]  #0x2A - J
    if ch == "K":
      return [0x00,0x66,0x6C,0x78,0x78,0x6C,0x66,0x00]  #0x2B - K
    if ch == "L":
      return [0x00,0x60,0x60,0x60,0x60,0x60,0x7E,0x00]  #0x2C - L
    if ch == "M":
      return [0x00,0x63,0x77,0x7F,0x6B,0x63,0x63,0x00]  #0x2D - M
    if ch == "N":
      return [0x00,0x66,0x76,0x7E,0x7E,0x6E,0x66,0x00]  #0x2E - N
    if ch == "O":
      return [0x00,0x3C,0x66,0x66,0x66,0x66,0x3C,0x00]  #0x2F - O

    if ch == "P":
      return [0x00,0x7C,0x66,0x66,0x7C,0x60,0x60,0x00]  #0x30 - P
    if ch == "Q":
      return [0x00,0x3C,0x66,0x66,0x66,0x6C,0x36,0x00]  #0x31 - Q
    if ch == "R":
      return [0x00,0x7C,0x66,0x66,0x7C,0x6C,0x66,0x00]  #0x32 - R
    if ch == "S":
      return [0x00,0x3C,0x60,0x3C,0x06,0x06,0x3C,0x00]  #0x33 - S
    if ch == "T":
      return [0x00,0x7E,0x18,0x18,0x18,0x18,0x18,0x00]  #0x34 - T
    if ch == "U":
      return [0x00,0x66,0x66,0x66,0x66,0x66,0x7E,0x00]  #0x35 - U
    if ch == "V":
      return [0x00,0x66,0x66,0x66,0x66,0x3C,0x18,0x00]  #0x36 - V
    if ch == "W":
      return [0x00,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00]  #0x37 - W
    if ch == "X":
      return [0x00,0x66,0x66,0x3C,0x3C,0x66,0x66,0x00]  #0x38 - X
    if ch == "Y":
      return [0x00,0x66,0x66,0x3C,0x18,0x18,0x18,0x00]  #0x39 - Y
    if ch == "Z":
      return [0x00,0x7E,0x0C,0x18,0x30,0x60,0x7E,0x00]  #0x3A - Z
    if ch == "[":
      return [0x00,0x1E,0x18,0x18,0x18,0x18,0x1E,0x00]  #0x3B - [
    if ch == "\\":
      return [0x00,0x40,0x60,0x30,0x18,0x0C,0x06,0x00]  #0x3C - \
    if ch == "]":
      return [0x00,0x78,0x18,0x18,0x18,0x18,0x78,0x00]  #0x3D - ]
    if ch == "^":
      return [0x00,0x08,0x1C,0x36,0x63,0x00,0x00,0x00]  #0x3E - ^
    if ch == "_":
      return [0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00]  #0x3F - underline

    if ch == 27:
      return [0x78,0x60,0x78,0x60,0x7E,0x18,0x1E,0x00]  #0x5B - display escape

    if ch == "a":
      return [0x00,0x00,0x3C,0x06,0x3E,0x66,0x3E,0x00]  #0x61 - a
    if ch == "b":
      return [0x00,0x60,0x60,0x7C,0x66,0x66,0x7C,0x00]  #0x62 - b
    if ch == "c":
      return [0x00,0x00,0x3C,0x60,0x60,0x60,0x3C,0x00]  #0x63 - c
    if ch == "d":
      return [0x00,0x06,0x06,0x3E,0x66,0x66,0x3E,0x00]  #0x64 - d
    if ch == "e":
      return [0x00,0x00,0x3C,0x66,0x7E,0x60,0x3C,0x00]  #0x65 - e
    if ch == "f":
      return [0x00,0x0E,0x18,0x3E,0x18,0x18,0x18,0x00]  #0x66 - f
    if ch == "g":
      return [0x00,0x00,0x3E,0x66,0x66,0x3E,0x06,0x7C]  #0x67 - g
    if ch == "h":
      return [0x00,0x60,0x60,0x7C,0x66,0x66,0x66,0x00]  #0x68 - h
    if ch == "i":
      return [0x00,0x18,0x00,0x38,0x18,0x18,0x3C,0x00]  #0x69 - i
    if ch == "j":
      return [0x00,0x06,0x00,0x06,0x06,0x06,0x06,0x3C]  #0x6A - j
    if ch == "k":
      return [0x00,0x60,0x60,0x6C,0x78,0x6C,0x66,0x00]  #0x6B - k
    if ch == "l":
      return [0x00,0x38,0x18,0x18,0x18,0x18,0x3C,0x00]  #0x6C - l
    if ch == "m":
      return [0x00,0x00,0x66,0x7F,0x7F,0x6B,0x63,0x00]  #0x6D - m
    if ch == "n":
      return [0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x00]  #0x6E - n
    if ch == "o":
      return [0x00,0x00,0x3C,0x66,0x66,0x66,0x3C,0x00]  #0x6F - o

    if ch == "p":
      return [0x00,0x00,0x7C,0x66,0x66,0x7C,0x60,0x60]  #0x70 - p
    if ch == "q":
      return [0x00,0x00,0x3E,0x66,0x66,0x3E,0x06,0x06]  #0x71 - q
    if ch == "r":
      return [0x00,0x00,0x7C,0x66,0x60,0x60,0x60,0x00]  #0x72 - r
    if ch == "s":
      return [0x00,0x00,0x3E,0x60,0x3C,0x06,0x7C,0x00]  #0x73 - s
    if ch == "t":
      return [0x00,0x18,0x7E,0x18,0x18,0x18,0x0E,0x00]  #0x74 - t
    if ch == "u":
      return [0x00,0x00,0x66,0x66,0x66,0x66,0x3E,0x00]  #0x75 - u
    if ch == "v":
      return [0x00,0x00,0x66,0x66,0x66,0x3C,0x18,0x00]  #0x76 - v
    if ch == "w":
      return [0x00,0x00,0x63,0x6B,0x7F,0x3E,0x36,0x00]  #0x77 - w
    if ch == "x":
      return [0x00,0x00,0x66,0x3C,0x18,0x3C,0x66,0x00]  #0x78 - x
    if ch == "y":
      return [0x00,0x00,0x66,0x66,0x66,0x3E,0x0C,0x78]  #0x79 - y
    if ch == "z":
      return [0x00,0x00,0x7E,0x0C,0x18,0x30,0x7E,0x00]  #0x7A - z
    if ch == "|":
      return [0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18]  #0x7C - |

    return [0, 0, 0, 0, 0, 0 ,0 , 0]

def rotate_image_90(image):
    # Get the dimensions of the original image
    height = len(image)
    width = len(image[0])

    # Create a new image with swapped dimensions
    rotated_image = [[0] * height for _ in range(width)]

    # Rotate the image
    for i in range(height):
        for j in range(width):
            rotated_image[j][height - 1 - i] = image[i][j]

    return rotated_image

# # Example bit array representing the monochrome graphic
# bit_array = [
#     0b00000000,
#     0b01111110,
#     0b01100000,
#     0b01111100,
#     0b00000110,
#     0b01100110,
#     0b00111100,
#     0b00000000
# ]

for inx in range(168): # range(168):

    bit_array = getit(inx)

    # Convert the bit array to a list of lists (image)
    image = [[(byte >> i) & 1 for i in range(7, -1, -1)] for byte in bit_array]

    # Rotate the image 90 degrees clockwise
    rotated_image = rotate_image_90(image)

    # Print the rotated image
    for row in rotated_image:
      pass
        #print("".join(str(bit) for bit in row))


    for row in rotated_image:
        hex_row = ''.join([hex(int(''.join(map(str, row[i:i+4])), 2))[2] for i in range(0, len(row), 4)])
        print(hex_row)

