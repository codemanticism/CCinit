import re
import sys
import subprocess
def process(text):
    open_file = open(text, "r")
    read = open_file.read()
    open_file.close()
    if ((read[0]) + (read[1])) == '/*':
        asterisk = False
        integer = 2
        for character in read[2:]:
            if (character) == '*':
                asterisk = True
            elif (character) == '/':
                if asterisk:
                    integer -= 1
                    break
            elif (character) == '\n':
                integer = 2
                break
            integer += 1
        for url in read[2:integer].split(" "):
            subprocess.run(["wget", url])
            process(url)
process(sys.argv[1])
