#!/usr/bin/env python3
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
        array = read[2:integer].split(" ")
        old = []
        count = 0
        int_ = 0
        for string in array:
            for character in string:
                if character == '/':
                    count += 1
            if count == 0:
                old = string.split("/")
            array[int_] = "/".join(old[0:(len(old) - count)]) + string
            int_ += 1
        for url in array:
            result = subprocess.run(["wget", url])
            process(url)
if len(sys.argv) > 1:
    process(sys.argv[1])
else:
    try:
        file_open = open("main.c", "r")
        file_open.read()
        file_open.close()
    except:
        file_write = open("main.c", "w")
        file_write.write("/**///<-- Here's where the URLs of the files go. The URL doesn't need to be complete: https://raw.githubusercontent.com/example/example/refs/heads/master/src/chmod.c /cat.c. Seperated by space, please. \nint main(){\n}")
        file_write.close() 
