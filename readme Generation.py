'''
######################################################

				Welcome to coder club

		A fully self made repo by Rahul Surana

You can use any of these files and twig them to your use

	have fun and also star mark this repo more to come

########################################################
'''



import os

f = open("README.md", "w")

f.write("# *Welcome To Coding Club*\n")

f.write("### <div style='text-align:right'><sub> - Rahul Surana</sub></div>\n")

f.write("### Going To Update This Repo Time To Time As I Continue My Journey To Competitive Programming\n")

f.write("### Please Do Star the Repo if it ever helps you. Also Would Like to Form a Community So we all can grow Together\n")

f.write("-  [ Whatsapp Group Link ](https://chat.whatsapp.com/FUV7H9SIBYKD3C5tgDluI6) \n")

f.write("### HYPERLINK To Code\n***\n")

dic = {}

for dirs in list(os.listdir(".")):
	if "." not in dirs:

		dic[dirs] = ("./"+"%20".join(list(dirs.split(" "))))
		x = f"[ {dirs} ]({dic[dirs]})"
		y = f"Problem Count:  {str(len(list(os.listdir(dirs))))}"
		z = 50 - len(dirs)
		s = f"-  {x:}   {''.join(['&nbsp;' for i in range(z)])}   {y}\n"
		print(s)
		f.write(s)
		
print(dic)
c = len(dic)
print(f"### Total Code Count : {c}") 
f.write(f"### Total Code Count : {c}") 
f.close()
