#!/bin/python
#****************************************************
#Purpose: Python Program                            *
#Author: Hussain Mehdi                               *
#****************************************************/
import sys			#imports
import os
import re

def rec(path,pattern):
    data = []
    for filename in os.listdir(path):		#Looping through
        fullname= str(os.path.join(path,filename))		#Checking wether file or directory
        if os.path.isfile(fullname):				#Matching filename to patter entered
            if re.match(pattern,fullname) != None:
                data.append(filename)
        else:
            temp = rec(fullname,pattern)		#Running it repeatedly to get all files
            data.extend(temp)
    return data				

if __name__ == '__main__':
 
    pattern = sys.argv[1]		#Getting pattern from cm line
    fileName = sys.argv[2]		#Getting Output file name from cm line
    
    files = rec(os.getcwd(),pattern)		#calls the function rec
    
    w = open(fileName,'w')			#opens file to write output
    
    for file in files:
        w.write(file+'\n')	#Writing the data to the file
        
    w.flush()		#Flushing the open 
    w.close()		#Closing the file after write complete
 
