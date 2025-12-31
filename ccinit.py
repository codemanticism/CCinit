#!/usr/bin/env python3
import os
import re
import sys
import subprocess
libraries = []
def process(text):
    global libraries
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
        new_array = []
        old = []
        count = 0
        for string in array:
            if len(string) > 0:
                if string[0] == '/':
                    count = 0
                    for character in string:
                        if character == '/':
                            count += 1
                    new_array.append( "/".join(old[:(len(old) - count)]) + string )
                else:
                    new_array.append( string )
                    old = string.split("/") 
        for url in new_array:
            divisions = url.split("/")
            try:            
                read_file = open(divisions[len(divisions) - 1], "r")
                read_file.read()
                read_file.close()
            except:
                result = subprocess.run(["wget", url])
                libraries.append(divisions[len(divisions) - 1])
                process(divisions[len(divisions) - 1])
def function(argument):
    global library
    process(argument)
    read_file = open("main.c", "r")
    text_read_file = read_file.read()
    read_file.close()
    write_file = open("main-backup.c", "w")
    write_file.write(text_read_file)
    write_file.close() 
    write_file_2 = open("main.c", "w")
    str_ = []
    for library in libraries:
        str_.append('#include "')
        str_.append(library)
        str_.append('"\n')
    str_.append(text_read_file)    
    write_file_2.write("".join(str_))
    result = subprocess.run(["bash", "compile.sh"])
    write_file_2.close()
    write_file_3 = open("main.c", "w")
    write_file_3.write(text_read_file)
    write_file_3.close()
    os.remove("main-backup.c")
if len(sys.argv) > 1:
    function(sys.argv[1])        
else:
    try:
        file_open = open("main.c", "r")
        file_open.read()
        file_open.close()
        function(sys.argv[1])
    except:
        file_write = open("main.c", "w")
        file_write.write('/**/\n//^Where the URLs go.\n#include "project.h"\nint main(){\n}')
        file_write.close() 
    try:
        file_open = open("compile.sh", "r")
        file_open.read()
        file_open.close()
    except:
        file_write = open("compile.sh", "w")
        file_write.write("gcc main.c *.h -o main")
        file_write.close() 
