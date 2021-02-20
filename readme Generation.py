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

f.write("# *Welcome To Coder Club*\n")

f.write("### <div style='text-align:right'><sub> - Rahul Surana</sub></div>\n")

f.write("### Going To Update This Repo Time To Time As I Continue My Journey To Competitive Programming\n")

f.write("### HYPERLINK To Code\n***\n")

dic = {}

for dirs in list(os.listdir(".")):
	# for r in root:
	print(dirs +" " + str('.' in dirs))
	# for filename in files:
	if not '.' in dirs:
		for files in os.listdir(dirs):	
			dic[files[:-2]] = "./"+dirs+"/"+files
			f.write("-  [ "+files[:-2]+" ](./"+"%20".join(list(dirs.split(" ")))+"/"+"%20".join(list(files.split(" ")))+") \n")
			# for files in os.listdir(d):
			# 	print(files)

print(dic)
f.close()