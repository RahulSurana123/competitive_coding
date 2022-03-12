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

f.write("# *Welcome To My Repository*\n")

f.write("### <div style='text-align:right'><sub> - Rahul Surana</sub></div>\n")

f.write("### Going To Update This Repo Time To Time As I Continue My Journey To Competitive Programming\n")

f.write("### Please Do Star the Repo if it ever helps you. Also Would Like to Form a Community So we all can grow Together\n")

f.write("### HYPERLINK To Code\n***\n")

dic = {}
ml = 0


f.write("| Platform  |  Problem Count |\n")

f.write("| --------  |  ------------- |\n")


for dirs in list(os.listdir(".")):
	if "." not in dirs:

		dic[dirs] = ("./"+"%20".join(list(dirs.split(" "))))
		x = f"[ {dirs} ]({dic[dirs]})"
		y = f" {str(len(list(os.listdir(dirs))))}"
		# print(len(dirs))
		s = f"|    {x}     |     {y}    |\n"
		ml+=int(y)
		f.write(s)
		
# print(dic)
c = ml
print(f"### Total Code Count : {c}") 
f.write(f"### Total Code Count : {c}") 
f.close()
