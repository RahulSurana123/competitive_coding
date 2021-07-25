

'''



Solution by Rahul Surana    


**********************************************************************************************


You are given an array  nums  consisting of  N  integers where  N  is even. 

You have to perform the following operation  N/2  times: 

 
    Select <span class="mathjax-latex"><span class="MathJax_Preview" style="color: inherit;"></span><span class="MathJax_SVG" id="MathJax-Element-1-Frame" tabindex="0" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mi>n</mi><mi>u</mi><mi>m</mi><msub><mi>s</mi><mi>i</mi></msub><mo>,</mo><mi>n</mi><mi>u</mi><mi>m</mi><msub><mi>s</mi><mi>j</mi></msub></math>" role="presentation" style="font-size: 175%; display: inline-block; position: relative;"><svg xmlns:xlink="http://www.w3.org/1999/xlink" width="14.819ex" height="2.664ex" viewBox="0 -573.5 6380.3 1147.1" role="img" focusable="false" style="vertical-align: -1.332ex;" aria-hidden="true"><defs><path stroke-width="1" id="E1-MJMATHI-6E" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E1-MJMATHI-75" d="M21 287Q21 295 30 318T55 370T99 420T158 442Q204 442 227 417T250 358Q250 340 216 246T182 105Q182 62 196 45T238 27T291 44T328 78L339 95Q341 99 377 247Q407 367 413 387T427 416Q444 431 463 431Q480 431 488 421T496 402L420 84Q419 79 419 68Q419 43 426 35T447 26Q469 29 482 57T512 145Q514 153 532 153Q551 153 551 144Q550 139 549 130T540 98T523 55T498 17T462 -8Q454 -10 438 -10Q372 -10 347 46Q345 45 336 36T318 21T296 6T267 -6T233 -11Q189 -11 155 7Q103 38 103 113Q103 170 138 262T173 379Q173 380 173 381Q173 390 173 393T169 400T158 404H154Q131 404 112 385T82 344T65 302T57 280Q55 278 41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E1-MJMATHI-6D" d="M21 287Q22 293 24 303T36 341T56 388T88 425T132 442T175 435T205 417T221 395T229 376L231 369Q231 367 232 367L243 378Q303 442 384 442Q401 442 415 440T441 433T460 423T475 411T485 398T493 385T497 373T500 364T502 357L510 367Q573 442 659 442Q713 442 746 415T780 336Q780 285 742 178T704 50Q705 36 709 31T724 26Q752 26 776 56T815 138Q818 149 821 151T837 153Q857 153 857 145Q857 144 853 130Q845 101 831 73T785 17T716 -10Q669 -10 648 17T627 73Q627 92 663 193T700 345Q700 404 656 404H651Q565 404 506 303L499 291L466 157Q433 26 428 16Q415 -11 385 -11Q372 -11 364 -4T353 8T350 18Q350 29 384 161L420 307Q423 322 423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 181Q151 335 151 342Q154 357 154 369Q154 405 129 405Q107 405 92 377T69 316T57 280Q55 278 41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E1-MJMATHI-73" d="M131 289Q131 321 147 354T203 415T300 442Q362 442 390 415T419 355Q419 323 402 308T364 292Q351 292 340 300T328 326Q328 342 337 354T354 372T367 378Q368 378 368 379Q368 382 361 388T336 399T297 405Q249 405 227 379T204 326Q204 301 223 291T278 274T330 259Q396 230 396 163Q396 135 385 107T352 51T289 7T195 -10Q118 -10 86 19T53 87Q53 126 74 143T118 160Q133 160 146 151T160 120Q160 94 142 76T111 58Q109 57 108 57T107 55Q108 52 115 47T146 34T201 27Q237 27 263 38T301 66T318 97T323 122Q323 150 302 164T254 181T195 196T148 231Q131 256 131 289Z"></path><path stroke-width="1" id="E1-MJMATHI-69" d="M184 600Q184 624 203 642T247 661Q265 661 277 649T290 619Q290 596 270 577T226 557Q211 557 198 567T184 600ZM21 287Q21 295 30 318T54 369T98 420T158 442Q197 442 223 419T250 357Q250 340 236 301T196 196T154 83Q149 61 149 51Q149 26 166 26Q175 26 185 29T208 43T235 78T260 137Q263 149 265 151T282 153Q302 153 302 143Q302 135 293 112T268 61T223 11T161 -11Q129 -11 102 10T74 74Q74 91 79 106T122 220Q160 321 166 341T173 380Q173 404 156 404H154Q124 404 99 371T61 287Q60 286 59 284T58 281T56 279T53 278T49 278T41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E1-MJMAIN-2C" d="M78 35T78 60T94 103T137 121Q165 121 187 96T210 8Q210 -27 201 -60T180 -117T154 -158T130 -185T117 -194Q113 -194 104 -185T95 -172Q95 -168 106 -156T131 -126T157 -76T173 -3V9L172 8Q170 7 167 6T161 3T152 1T140 0Q113 0 96 17Z"></path><path stroke-width="1" id="E1-MJMATHI-6A" d="M297 596Q297 627 318 644T361 661Q378 661 389 651T403 623Q403 595 384 576T340 557Q322 557 310 567T297 596ZM288 376Q288 405 262 405Q240 405 220 393T185 362T161 325T144 293L137 279Q135 278 121 278H107Q101 284 101 286T105 299Q126 348 164 391T252 441Q253 441 260 441T272 442Q296 441 316 432Q341 418 354 401T367 348V332L318 133Q267 -67 264 -75Q246 -125 194 -164T75 -204Q25 -204 7 -183T-12 -137Q-12 -110 7 -91T53 -71Q70 -71 82 -81T95 -112Q95 -148 63 -167Q69 -168 77 -168Q111 -168 139 -140T182 -74L193 -32Q204 11 219 72T251 197T278 308T289 365Q289 372 288 376Z"></path></defs><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#E1-MJMATHI-6E" x="0" y="0"></use><use xlink:href="#E1-MJMATHI-75" x="600" y="0"></use><use xlink:href="#E1-MJMATHI-6D" x="1173" y="0"></use><g transform="translate(2051,0)"><use xlink:href="#E1-MJMATHI-73" x="0" y="0"></use><use transform="scale(0.914)" xlink:href="#E1-MJMATHI-69" x="513" y="-286"></use></g><use xlink:href="#E1-MJMAIN-2C" x="2936" y="0"></use><use xlink:href="#E1-MJMATHI-6E" x="3382" y="0"></use><use xlink:href="#E1-MJMATHI-75" x="3982" y="0"></use><use xlink:href="#E1-MJMATHI-6D" x="4555" y="0"></use><g transform="translate(5433,0)"><use xlink:href="#E1-MJMATHI-73" x="0" y="0"></use><use transform="scale(0.914)" xlink:href="#E1-MJMATHI-6A" x="513" y="-286"></use></g></g></svg><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi><mi>u</mi><mi>m</mi><msub><mi>s</mi><mi>i</mi></msub><mo>,</mo><mi>n</mi><mi>u</mi><mi>m</mi><msub><mi>s</mi><mi>j</mi></msub></math></span></span><script type="math/tex" id="MathJax-Element-1">nums_i,nums_j</script></span> such that <span class="mathjax-latex"><span class="MathJax_Preview" style="color: inherit;"></span><span class="MathJax_SVG" id="MathJax-Element-2-Frame" tabindex="0" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mo stretchy=&quot;false&quot;>(</mo><mi>i</mi><mo>&amp;#x2260;</mo><mi>j</mi><mo stretchy=&quot;false&quot;>)</mo></math>" role="presentation" style="font-size: 175%; display: inline-block; position: relative;"><svg xmlns:xlink="http://www.w3.org/1999/xlink" width="6.668ex" height="3.195ex" viewBox="0 -916.5 2871.1 1375.7" role="img" focusable="false" style="vertical-align: -1.067ex;" aria-hidden="true"><defs><path stroke-width="1" id="E2-MJMAIN-28" d="M94 250Q94 319 104 381T127 488T164 576T202 643T244 695T277 729T302 750H315H319Q333 750 333 741Q333 738 316 720T275 667T226 581T184 443T167 250T184 58T225 -81T274 -167T316 -220T333 -241Q333 -250 318 -250H315H302L274 -226Q180 -141 137 -14T94 250Z"></path><path stroke-width="1" id="E2-MJMATHI-69" d="M184 600Q184 624 203 642T247 661Q265 661 277 649T290 619Q290 596 270 577T226 557Q211 557 198 567T184 600ZM21 287Q21 295 30 318T54 369T98 420T158 442Q197 442 223 419T250 357Q250 340 236 301T196 196T154 83Q149 61 149 51Q149 26 166 26Q175 26 185 29T208 43T235 78T260 137Q263 149 265 151T282 153Q302 153 302 143Q302 135 293 112T268 61T223 11T161 -11Q129 -11 102 10T74 74Q74 91 79 106T122 220Q160 321 166 341T173 380Q173 404 156 404H154Q124 404 99 371T61 287Q60 286 59 284T58 281T56 279T53 278T49 278T41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E2-MJMAIN-2260" d="M166 -215T159 -215T147 -212T141 -204T139 -197Q139 -190 144 -183L306 133H70Q56 140 56 153Q56 168 72 173H327L406 327H72Q56 332 56 347Q56 360 70 367H426Q597 702 602 707Q605 716 618 716Q625 716 630 712T636 703T638 696Q638 692 471 367H707Q722 359 722 347Q722 336 708 328L451 327L371 173H708Q722 163 722 153Q722 140 707 133H351Q175 -210 170 -212Q166 -215 159 -215Z"></path><path stroke-width="1" id="E2-MJMATHI-6A" d="M297 596Q297 627 318 644T361 661Q378 661 389 651T403 623Q403 595 384 576T340 557Q322 557 310 567T297 596ZM288 376Q288 405 262 405Q240 405 220 393T185 362T161 325T144 293L137 279Q135 278 121 278H107Q101 284 101 286T105 299Q126 348 164 391T252 441Q253 441 260 441T272 442Q296 441 316 432Q341 418 354 401T367 348V332L318 133Q267 -67 264 -75Q246 -125 194 -164T75 -204Q25 -204 7 -183T-12 -137Q-12 -110 7 -91T53 -71Q70 -71 82 -81T95 -112Q95 -148 63 -167Q69 -168 77 -168Q111 -168 139 -140T182 -74L193 -32Q204 11 219 72T251 197T278 308T289 365Q289 372 288 376Z"></path><path stroke-width="1" id="E2-MJMAIN-29" d="M60 749L64 750Q69 750 74 750H86L114 726Q208 641 251 514T294 250Q294 182 284 119T261 12T224 -76T186 -143T145 -194T113 -227T90 -246Q87 -249 86 -250H74Q66 -250 63 -250T58 -247T55 -238Q56 -237 66 -225Q221 -64 221 250T66 725Q56 737 55 738Q55 746 60 749Z"></path></defs><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#E2-MJMAIN-28" x="0" y="0"></use><use xlink:href="#E2-MJMATHI-69" x="389" y="0"></use><use xlink:href="#E2-MJMAIN-2260" x="1012" y="0"></use><use xlink:href="#E2-MJMATHI-6A" x="2069" y="0"></use><use xlink:href="#E2-MJMAIN-29" x="2481" y="0"></use></g></svg><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mi>i</mi><mo>≠</mo><mi>j</mi><mo stretchy="false">)</mo></math></span></span><script type="math/tex" id="MathJax-Element-2">(i\neq j)</script></span> from the list 
    Take their  bitwise OR , add the value of the least significant set bit to the score 
    Delete those two numbers 
 

If the selected numbers are  5=(101)<sub>2</sub>  and  7=(111)<sub>2</sub>  then the  bitwise OR  of the two numbers is  7=(111)<sub>2</sub> . So, the least significant bit of  7  i.e.  1=(001)<sub>2</sub>  will be added to the current score. 

Notes  

    1 -based indexing is followed 
    A  bitwise OR  is a binary operation that takes two bit patterns of equal length and performs the logical inclusive OR operation on each pair of corresponding bits. The result in each position is 0 if both bits are 0, while otherwise, the result is  1 .  
    Strings in ()<sub>2</sub> denote the binary representation. 
 

Task  

Print the maximum possible score. 

Example  
Assumptions  
    N=4  
    nums = [1,2,1,4]  
 

Approach  

 
    For the given case pairing  (1, 1), (2, 4)  that is  (nums[1], nums[3]), (nums[2], nums[4])  with  1 -based indexing results in a maximum score of  3 , pairing like  (4, 1),(1, 2)  that is  (nums[4], nums[1]), (nums[3], nums[2])  results in  2 . 
 

Hence, the answer is  3 . 

Function description  

Complete the  MaxPairs  function provided in the editor. The function takes the following  2  parameters and returns the maximum possible score based on the parameters. 
 
    N:  Represents   an integer denoting the total number of integers 
    nums : Represents   an array containing  N  integers 
 

Input format :

Note : This is the input format that you must use to provide custom input (available above the  Compile and Test  button). 

The first line contains  T  denoting   the number   of test cases.  T  also specifies the number of times you have to run the  MaxPairs  function on a different set of inputs 

For each test case:     
    The first line contains  N  denoting   the number   of integers.  
    The second line contains  N  space-separated integers denoting the elements of array  nums . 
     
     
 

Output format:
    
For each test case, print the answer representing the maximum possible score in a new line. 


***************************************************************************************


'''


import math

def ffs(n):
    return (n | -n).bit_length()-1 

def MaxPairs (N, nums):
    ar = [0] * 64
    for i in nums:
        # j = i
        ar[ffs(i)] += 1
        # if(not pow_of_2(i)):
        #     ar[0]+=1
        # else:
        #     ar[int(math.log2(j))] += 1
    # for i in range(0,5):
    #     print(ar[i], sep = " ")
    ans = 0
    f = True
    for i in range(0,64):
        ans += int(ar[i]/2) * pow(2,i)
        if(ar[i] % 2 == 1):
            if(f):
                ans += pow(2,i)
                f = False
            else:
                f = True

        # print(ans)    
    return ans

T = int(input())
for _ in range(T):
    N = int(input())
    nums = list(map(int, input().split()))

    out_ = MaxPairs(N, nums)
    print (out_)
