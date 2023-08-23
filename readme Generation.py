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
f.write("#### Here are links to some of my profile \n")
f.write('</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<!-- Leetcode --><a href="https://leetcode.com/rasuru04/" target="_blank"> <img src="https://miro.medium.com/max/1838/1*gBkMCGTAdSk4tu17SCa7RQ.png" alt="leetcode" width="100" height="45"/>  </a>')
f.write('&nbsp;&nbsp;&nbsp;&nbsp;<!-- CodeChef --><a href="https://www.codechef.com/users/suru_4851" target="_blank"> <img src="https://cdn.codechef.com/sites/all/themes/abessive/cc-logo.png" alt="codechef" width="100" height="45"/>  </a>')
f.write('&nbsp;&nbsp;&nbsp;&nbsp;<!-- Hacker Earth --><a href="https://www.hackerearth.com/@Rahul_surana" target="_blank"> <img src="https://static-fastly.hackerearth.com/newton/static/images/he-header-logo.svg" alt="hackerearth" width="150" height="45"/>  </a>')
f.write('&nbsp;&nbsp;&nbsp;&nbsp;<!-- Code Forces --><a href="https://codeforces.com/profile/suru_4851" target="_blank"> <img src="https://codeforces.org/s/55900/images/codeforces-sponsored-by-ton.png" alt="codeforce" width="150" height="45"/>  </a>\n')

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
f.write(f"\n### Total Code Count : {c}") 
f.close()
