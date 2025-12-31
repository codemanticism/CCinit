#!/usr/bin/env python3
import os
import re
import sys
import subprocess
libraries = []
already_done = {}
files = {}
dependencies = {}
def process(text):
    global libraries
    global files
    global dependencies
    global already_done
    open_file = open(text, "r")
    read = open_file.read()
    already_done[text] = False
    try:
        files[text].append( read )
    except:
        files[text] = [read]
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
                dependencies[text].append( divisions[len(divisions) - 1] )
            except:
                dependencies[text] = [divisions[len(divisions) - 1]]
            try:            
                read_file = open(divisions[len(divisions) - 1], "r")
                read_file.read()
                read_file.close()
            except:
                result = subprocess.run(["wget", url])
                libraries.append(divisions[len(divisions) - 1])
                process(divisions[len(divisions) - 1])
def function(argument):
    global libraries
    global files
    global dependencies
    include = '#include'
    process(argument)
    read_file = open("main.c", "r")
    global already_done
    text_read_file = read_file.read()
    read_file.close()
    pos = re.search(r'\n[^\n"](.*)\/\*main\*\/.*[^\n"][\s\S]*', text_read_file)
    text_read_file_ = text_read_file[0:pos]
    write_file = open("main-backup.c", "w")
    write_file.write(text_read_file)
    write_file.close() 
    write_file_2 = open("main.c", "w")
    str_ = []
    includes = []
    files_keys = list( files.keys() )
    file_count = len(files) - 1
    while False in already_done:
        print(already_done)
        while file_count >= 0:
            boolean = False
            key = files_keys[file_count]
            print(dependences[key])
            for dependence in dependences[key]:
                if dependence not in already_done:
                    boolean = True
            if boolean:
                break
            file = files[key]
            position = file.find("\n\n")
            str__ =  file[0:position]
            i = 0;
            while(i < len(str__)):
                _str = str__[i:(i + len(include))]
                if _str == include:
                    an_include = str__[(i + len(include) + 1):]
                    end = an_include.find("\n")
                    the_str = an_include[:end]
                    if the_str not in includes:
                        includes.append(the_str)
                i += 1
            already_done[key] = True
            file_count -= 1
    for include_item in includes:
        str_.append("#include ")
        str_.append(include_item)
        str_.append("\n")
    str_.append("\n")
    for file in files:
        position = file.find("\n\n")
        str_.append( "\n" )
        str_.append( file[(position + 2):] )
    str_.append(text_read_file_)
    print("".join(str_))
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
        file_write.write('/**/\n//^Where the URLs go.\n/*main*/\nint main(){\n}')
        file_write.close() 
    try:
        file_open = open("compile.sh", "r")
        file_open.read()
        file_open.close()
    except:
        file_write = open("compile.sh", "w")
        file_write.write("gcc main.c -o main")
        file_write.close() 
