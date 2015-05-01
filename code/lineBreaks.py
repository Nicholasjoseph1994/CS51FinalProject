inputt = open("big.txt", 'r')
output = open("bigFormatted.txt", 'w')

for line in inputt:
    words = line.split()
    for w in words:
        output.write(w + "\n")

