'''
######################################################

				Welcome to coder club

		A fully self made repo by Rahul Surana

You can use any of these files and twig them to your use

	have fun and also star mark this repo more to come

########################################################
'''



import os

from os.path import isfile, join

fs = open("README.md", "w")

fs.write("# *Welcome To Coding Club*\n")

fs.write("### <div style='text-align:right'><sub> - Rahul Surana</sub></div>\n")

fs.write("### Going To Update This Repo Time To Time As I Continue My Journey To Competitive Programming\n")

fs.write("### Please Do Star the Repo if it ever helps you. Also Would Like to Form a Community So we all can grow Together\n")

fs.write("-  [ Whatsapp Group Link ](https://chat.whatsapp.com/FUV7H9SIBYKD3C5tgDluI6) \n")

fs.write("### HYPERLINK To Code\n***\n")

dic = {}

# ls = [ i if isfile(i) for i in os.listdir(".") ]

for r,d,f in list(os.walk(os.getcwd())):
	print(f)
	for files in f:	
		if files[-3:] == ".py":
			dic[files[:-3]] = ("./"+"%20".join(list(files.split(" ")))).replace("?","%3F")
			fs.write("-  [ "+files[:-3]+" ]("+dic[files[:-3]]+") \n")
		else:
			dic[files[:-4]] = ("./"+"%20".join(list(files.split(" ")))).replace("?","%3F") 
			fs.write("-  [ "+files[:-4]+" ]("+dic[files[:-4]]+") \n")

print(dic)
c = len(dic)
print(f"### Total Code Count : {c}") 
fs.write(f"### Total Code Count : {c}") 
fs.close()
