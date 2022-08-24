/*


******************************************************************

<div class="problem-description assessment-problem-description no-select"><div class="algorithm" data-id="4da61634ab8a4637985ddcc97e4e1784"><div class="float-left width-100 padding-bottom-10 lighter-border-bottom margin-bottom-20 margin-top-24"><div class="content-heading inline-block semi-bold margin-right-10">Question</div><div class="serial-number content-heading inline-block serial-number-4da61634ab8a4637985ddcc97e4e1784">1 </div><div class="weight-600 black-333 float-right inline-block"><div private_url_hash="4da61634ab8a4637985ddcc97e4e1784" class="algorithm-start-flow project-start-flow float-right inline-block padding-left-10 tool-tip flow-div-algorithm" title="See how to attempt this question."><i class="flow-help fa fa-question-circle font-size-16 light"></i></div><div class="problem-score max-marks inline-block max-marks-4da61634ab8a4637985ddcc97e4e1784">Max. score: 100.00</div></div></div><div class="clear"></div><div class="problem-statement problem-statement-4da61634ab8a4637985ddcc97e4e1784"><div class="semi-bold margin-bottom-20">MEX value</div><div class="algorithm-problem complete-problem-statement dark">You are given an array  A  consisting of  N  integers.

 Task 

Determine the maximum possible  MEX  of sequence  B  where the  i<sup>th</sup>  element  B<sub>i</sub> = A<sub>i</sub>  ⊕  C  where  C  is any constant non-negative integer.

 Note:  Mex of a sequence of numbers is the minimum non-negative number that is not present in the sequence as an element. For example,  MEX ([ 4, 0, 1, 1 ]) = 2 and  MEX ([ 1, 2 ]) = 0.

 Example 

 Assumptions 

 
	  N = 4  
	  A = [2, 3, 4, 5]  
 

 Approach 

 
	 Taking the value of  C = 1 , the obtained sequence becomes  B = [3, 2, 5, 4 ]. H ere the  MEX  of the sequence is 0. 
	 Taking the value of  C = 2 , the obtained sequence becomes  B = [0, 1, 6, 7 ]. H ere the  MEX  of the sequence is 2. 
	 Taking the value of  C = 3 , the obtained sequence becomes  B = [1, 0, 7, 6 ]. H ere the  MEX  of the sequence is 2. 
	 Taking the value of  C = 4 , the obtained sequence becomes  B = [1, 0, 7, 6 ]. H ere the  MEX  of the sequence is 2. 
	 Similarly, you can calculate  MEX  for other  C  as well. 
	 The maximum  MEX  you can get from all the sequences is  2  from the sequence where  C = {2,3,4,... etc}  as the numbers  0  and  1  are present in this sequence. 
 

Hence, the answer is 2.

 Function description 

Complete the  meximise  function provided in the editor. This function takes the following  2  parameters and returns the number of regions the plane is divided into:

 
	  N : Represents integer denoting the size of array  A  
	  A : Represents array of integers 
 

 Input format 

 Note:  This is the input format that you must use to provide custom input (available above the Compile and Test button).

 
	 The first line contains a single integer  T  denoting the number of test cases.  T  also specifies the number of times you have to run the  meximise  function on a different set of inputs. 
	 For each test case,
	 
		 The first line contains a single integer  N  denoting the number of integers in the array  A  
		 The second line contains  N  space-separated integers denoting the given array. 
	 
	 
 

 Output format 

For each test case in a new line, print a single integer representing the maximum possible  MEX  value of sequence  B  . 

 Constraints 

 <span class="mathjax-latex"><span class="MathJax_Preview" style="color: inherit;"></span><span class="MathJax_SVG" id="MathJax-Element-1-Frame" tabindex="0" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mn>1</mn><mo>&amp;#x2264;</mo><mi>T</mi><mo>&amp;#x2264;</mo><mn>10</mn></math>" role="presentation" style="font-size: 175%; display: inline-block; position: relative;"><svg xmlns:xlink="http://www.w3.org/1999/xlink" width="11.321ex" height="2.664ex" viewBox="0 -802.1 4874.1 1147.1" role="img" focusable="false" style="vertical-align: -0.801ex;" aria-hidden="true"><defs><path stroke-width="1" id="E1-MJMAIN-31" d="M213 578L200 573Q186 568 160 563T102 556H83V602H102Q149 604 189 617T245 641T273 663Q275 666 285 666Q294 666 302 660V361L303 61Q310 54 315 52T339 48T401 46H427V0H416Q395 3 257 3Q121 3 100 0H88V46H114Q136 46 152 46T177 47T193 50T201 52T207 57T213 61V578Z"></path><path stroke-width="1" id="E1-MJMAIN-2264" d="M674 636Q682 636 688 630T694 615T687 601Q686 600 417 472L151 346L399 228Q687 92 691 87Q694 81 694 76Q694 58 676 56H670L382 192Q92 329 90 331Q83 336 83 348Q84 359 96 365Q104 369 382 500T665 634Q669 636 674 636ZM84 -118Q84 -108 99 -98H678Q694 -104 694 -118Q694 -130 679 -138H98Q84 -131 84 -118Z"></path><path stroke-width="1" id="E1-MJMATHI-54" d="M40 437Q21 437 21 445Q21 450 37 501T71 602L88 651Q93 669 101 677H569H659Q691 677 697 676T704 667Q704 661 687 553T668 444Q668 437 649 437Q640 437 637 437T631 442L629 445Q629 451 635 490T641 551Q641 586 628 604T573 629Q568 630 515 631Q469 631 457 630T439 622Q438 621 368 343T298 60Q298 48 386 46Q418 46 427 45T436 36Q436 31 433 22Q429 4 424 1L422 0Q419 0 415 0Q410 0 363 1T228 2Q99 2 64 0H49Q43 6 43 9T45 27Q49 40 55 46H83H94Q174 46 189 55Q190 56 191 56Q196 59 201 76T241 233Q258 301 269 344Q339 619 339 625Q339 630 310 630H279Q212 630 191 624Q146 614 121 583T67 467Q60 445 57 441T43 437H40Z"></path><path stroke-width="1" id="E1-MJMAIN-30" d="M96 585Q152 666 249 666Q297 666 345 640T423 548Q460 465 460 320Q460 165 417 83Q397 41 362 16T301 -15T250 -22Q224 -22 198 -16T137 16T82 83Q39 165 39 320Q39 494 96 585ZM321 597Q291 629 250 629Q208 629 178 597Q153 571 145 525T137 333Q137 175 145 125T181 46Q209 16 250 16Q290 16 318 46Q347 76 354 130T362 333Q362 478 354 524T321 597Z"></path></defs><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#E1-MJMAIN-31" x="0" y="0"></use><use xlink:href="#E1-MJMAIN-2264" x="778" y="0"></use><use xlink:href="#E1-MJMATHI-54" x="1834" y="0"></use><use xlink:href="#E1-MJMAIN-2264" x="2816" y="0"></use><g transform="translate(3873,0)"><use xlink:href="#E1-MJMAIN-31"></use><use xlink:href="#E1-MJMAIN-30" x="500" y="0"></use></g></g></svg><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>T</mi><mo>≤</mo><mn>10</mn></math></span></span><script type="math/tex" id="MathJax-Element-1">1 \le T \le 10</script></span> 

 <span class="mathjax-latex"><span class="MathJax_Preview" style="color: inherit;"></span><span class="MathJax_SVG" id="MathJax-Element-2-Frame" tabindex="0" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mn>1</mn><mo>&amp;#x2264;</mo><mi>N</mi><mo>&amp;#x2264;</mo><msup><mn>10</mn><mn>5</mn></msup></math>" role="presentation" style="font-size: 175%; display: inline-block; position: relative;"><svg xmlns:xlink="http://www.w3.org/1999/xlink" width="13.043ex" height="3.461ex" viewBox="0 -1145.1 5615.8 1490" role="img" focusable="false" style="vertical-align: -0.801ex;" aria-hidden="true"><defs><path stroke-width="1" id="E2-MJMAIN-31" d="M213 578L200 573Q186 568 160 563T102 556H83V602H102Q149 604 189 617T245 641T273 663Q275 666 285 666Q294 666 302 660V361L303 61Q310 54 315 52T339 48T401 46H427V0H416Q395 3 257 3Q121 3 100 0H88V46H114Q136 46 152 46T177 47T193 50T201 52T207 57T213 61V578Z"></path><path stroke-width="1" id="E2-MJMAIN-2264" d="M674 636Q682 636 688 630T694 615T687 601Q686 600 417 472L151 346L399 228Q687 92 691 87Q694 81 694 76Q694 58 676 56H670L382 192Q92 329 90 331Q83 336 83 348Q84 359 96 365Q104 369 382 500T665 634Q669 636 674 636ZM84 -118Q84 -108 99 -98H678Q694 -104 694 -118Q694 -130 679 -138H98Q84 -131 84 -118Z"></path><path stroke-width="1" id="E2-MJMATHI-4E" d="M234 637Q231 637 226 637Q201 637 196 638T191 649Q191 676 202 682Q204 683 299 683Q376 683 387 683T401 677Q612 181 616 168L670 381Q723 592 723 606Q723 633 659 637Q635 637 635 648Q635 650 637 660Q641 676 643 679T653 683Q656 683 684 682T767 680Q817 680 843 681T873 682Q888 682 888 672Q888 650 880 642Q878 637 858 637Q787 633 769 597L620 7Q618 0 599 0Q585 0 582 2Q579 5 453 305L326 604L261 344Q196 88 196 79Q201 46 268 46H278Q284 41 284 38T282 19Q278 6 272 0H259Q228 2 151 2Q123 2 100 2T63 2T46 1Q31 1 31 10Q31 14 34 26T39 40Q41 46 62 46Q130 49 150 85Q154 91 221 362L289 634Q287 635 234 637Z"></path><path stroke-width="1" id="E2-MJMAIN-30" d="M96 585Q152 666 249 666Q297 666 345 640T423 548Q460 465 460 320Q460 165 417 83Q397 41 362 16T301 -15T250 -22Q224 -22 198 -16T137 16T82 83Q39 165 39 320Q39 494 96 585ZM321 597Q291 629 250 629Q208 629 178 597Q153 571 145 525T137 333Q137 175 145 125T181 46Q209 16 250 16Q290 16 318 46Q347 76 354 130T362 333Q362 478 354 524T321 597Z"></path><path stroke-width="1" id="E2-MJMAIN-35" d="M164 157Q164 133 148 117T109 101H102Q148 22 224 22Q294 22 326 82Q345 115 345 210Q345 313 318 349Q292 382 260 382H254Q176 382 136 314Q132 307 129 306T114 304Q97 304 95 310Q93 314 93 485V614Q93 664 98 664Q100 666 102 666Q103 666 123 658T178 642T253 634Q324 634 389 662Q397 666 402 666Q410 666 410 648V635Q328 538 205 538Q174 538 149 544L139 546V374Q158 388 169 396T205 412T256 420Q337 420 393 355T449 201Q449 109 385 44T229 -22Q148 -22 99 32T50 154Q50 178 61 192T84 210T107 214Q132 214 148 197T164 157Z"></path></defs><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#E2-MJMAIN-31" x="0" y="0"></use><use xlink:href="#E2-MJMAIN-2264" x="778" y="0"></use><use xlink:href="#E2-MJMATHI-4E" x="1834" y="0"></use><use xlink:href="#E2-MJMAIN-2264" x="3000" y="0"></use><g transform="translate(4057,0)"><use xlink:href="#E2-MJMAIN-31"></use><use xlink:href="#E2-MJMAIN-30" x="500" y="0"></use><use transform="scale(0.914)" xlink:href="#E2-MJMAIN-35" x="1094" y="396"></use></g></g></svg><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><msup><mn>10</mn><mn>5</mn></msup></math></span></span><script type="math/tex" id="MathJax-Element-2">1 \le N \le 10^5</script></span> 

<span class="mathjax-latex"><span class="MathJax_Preview" style="color: inherit;"></span><span class="MathJax_SVG" id="MathJax-Element-3-Frame" tabindex="0" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mn>1</mn><mo>&amp;#x2264;</mo><msub><mi>A</mi><mi>i</mi></msub><mo>&amp;#x2264;</mo><msup><mn>10</mn><mn>9</mn></msup></math>" role="presentation" style="font-size: 175%; display: inline-block; position: relative;"><svg xmlns:xlink="http://www.w3.org/1999/xlink" width="13.689ex" height="3.726ex" viewBox="0 -1145.1 5893.7 1604.3" role="img" focusable="false" style="vertical-align: -1.067ex;" aria-hidden="true"><defs><path stroke-width="1" id="E3-MJMAIN-31" d="M213 578L200 573Q186 568 160 563T102 556H83V602H102Q149 604 189 617T245 641T273 663Q275 666 285 666Q294 666 302 660V361L303 61Q310 54 315 52T339 48T401 46H427V0H416Q395 3 257 3Q121 3 100 0H88V46H114Q136 46 152 46T177 47T193 50T201 52T207 57T213 61V578Z"></path><path stroke-width="1" id="E3-MJMAIN-2264" d="M674 636Q682 636 688 630T694 615T687 601Q686 600 417 472L151 346L399 228Q687 92 691 87Q694 81 694 76Q694 58 676 56H670L382 192Q92 329 90 331Q83 336 83 348Q84 359 96 365Q104 369 382 500T665 634Q669 636 674 636ZM84 -118Q84 -108 99 -98H678Q694 -104 694 -118Q694 -130 679 -138H98Q84 -131 84 -118Z"></path><path stroke-width="1" id="E3-MJMATHI-41" d="M208 74Q208 50 254 46Q272 46 272 35Q272 34 270 22Q267 8 264 4T251 0Q249 0 239 0T205 1T141 2Q70 2 50 0H42Q35 7 35 11Q37 38 48 46H62Q132 49 164 96Q170 102 345 401T523 704Q530 716 547 716H555H572Q578 707 578 706L606 383Q634 60 636 57Q641 46 701 46Q726 46 726 36Q726 34 723 22Q720 7 718 4T704 0Q701 0 690 0T651 1T578 2Q484 2 455 0H443Q437 6 437 9T439 27Q443 40 445 43L449 46H469Q523 49 533 63L521 213H283L249 155Q208 86 208 74ZM516 260Q516 271 504 416T490 562L463 519Q447 492 400 412L310 260L413 259Q516 259 516 260Z"></path><path stroke-width="1" id="E3-MJMATHI-69" d="M184 600Q184 624 203 642T247 661Q265 661 277 649T290 619Q290 596 270 577T226 557Q211 557 198 567T184 600ZM21 287Q21 295 30 318T54 369T98 420T158 442Q197 442 223 419T250 357Q250 340 236 301T196 196T154 83Q149 61 149 51Q149 26 166 26Q175 26 185 29T208 43T235 78T260 137Q263 149 265 151T282 153Q302 153 302 143Q302 135 293 112T268 61T223 11T161 -11Q129 -11 102 10T74 74Q74 91 79 106T122 220Q160 321 166 341T173 380Q173 404 156 404H154Q124 404 99 371T61 287Q60 286 59 284T58 281T56 279T53 278T49 278T41 278H27Q21 284 21 287Z"></path><path stroke-width="1" id="E3-MJMAIN-30" d="M96 585Q152 666 249 666Q297 666 345 640T423 548Q460 465 460 320Q460 165 417 83Q397 41 362 16T301 -15T250 -22Q224 -22 198 -16T137 16T82 83Q39 165 39 320Q39 494 96 585ZM321 597Q291 629 250 629Q208 629 178 597Q153 571 145 525T137 333Q137 175 145 125T181 46Q209 16 250 16Q290 16 318 46Q347 76 354 130T362 333Q362 478 354 524T321 597Z"></path><path stroke-width="1" id="E3-MJMAIN-39" d="M352 287Q304 211 232 211Q154 211 104 270T44 396Q42 412 42 436V444Q42 537 111 606Q171 666 243 666Q245 666 249 666T257 665H261Q273 665 286 663T323 651T370 619T413 560Q456 472 456 334Q456 194 396 97Q361 41 312 10T208 -22Q147 -22 108 7T68 93T121 149Q143 149 158 135T173 96Q173 78 164 65T148 49T135 44L131 43Q131 41 138 37T164 27T206 22H212Q272 22 313 86Q352 142 352 280V287ZM244 248Q292 248 321 297T351 430Q351 508 343 542Q341 552 337 562T323 588T293 615T246 625Q208 625 181 598Q160 576 154 546T147 441Q147 358 152 329T172 282Q197 248 244 248Z"></path></defs><g stroke="currentColor" fill="currentColor" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#E3-MJMAIN-31" x="0" y="0"></use><use xlink:href="#E3-MJMAIN-2264" x="778" y="0"></use><g transform="translate(1834,0)"><use xlink:href="#E3-MJMATHI-41" x="0" y="0"></use><use transform="scale(0.914)" xlink:href="#E3-MJMATHI-69" x="820" y="-286"></use></g><use xlink:href="#E3-MJMAIN-2264" x="3278" y="0"></use><g transform="translate(4335,0)"><use xlink:href="#E3-MJMAIN-31"></use><use xlink:href="#E3-MJMAIN-30" x="500" y="0"></use><use transform="scale(0.914)" xlink:href="#E3-MJMAIN-39" x="1094" y="396"></use></g></g></svg><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><msub><mi>A</mi><mi>i</mi></msub><mo>≤</mo><msup><mn>10</mn><mn>9</mn></msup></math></span></span><script type="math/tex" id="MathJax-Element-3">1 \le A_i \le 10^9</script></span>

 Code snippets (also called starter code/boilerplate code) 

This question has code snippets for C, CPP, Java, and Python.</div><div class="clear"></div></div></div><div class="clear"></div><div id="input-output-box-4da61634ab8a4637985ddcc97e4e1784" class="margin-top-12"><div id="sample-test-case-1630753486743" class="sample-test-case"><div class="view-sample-test-case d-flex margin-bottom-12"><div class="padding-right-36 w-50"><div class="d-flex title-container"><div class="sample-title">Sample input 1</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 100px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">4</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2 3 4 5</pre><pre style="position: absolute; left: 0px; top: 60px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">4</pre><pre style="position: absolute; left: 0px; top: 80px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">10 7 8 23</pre></div></div></div></div></div><div class="w-50"><div class="d-flex title-container"><div class="sample-title">Sample output 1</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 60px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;"></pre></div></div></div></div></div></div><div class="margin-top-24"><div class="sample-title">Explanation</div><div class="explanation">The first line contains the number of test cases,  T = 2 .

 The first test case 

Described in the example section of the problem.

 The second test case 

 Given 

 
	  N = 4  
	  A = [10, 7, 8, 23]  
 

 Approach 

 
	 Taking the value of  C = 1 , the obtained sequence becomes  B = [11, 6, 9, 22]. H ere the  MEX  of the sequence is 0. 
	 Taking the value of  C = 2 , the obtained sequence becomes  B = [8, 5, 10, 21]. H ere the  MEX  of the sequence is 0. 
	 Taking the value of  C = 3 , the obtained sequence becomes  B = [9, 4, 11, 20]. H ere the  MEX  of the sequence is 0. 
	 Similarly, taking the value of  C = 7 , the obtained sequence becomes  B = [13, 0, 15, 16]. H ere the  MEX  of the sequence is 1. 
	 The maximum  MEX  you can get from all the sequences is  1  from the sequence where  C = 7  as the number  0  is present in this sequence. 
 

Hence, the answer is  1 .</div></div><textarea class="text-area-to-copy"></textarea></div><div><div class="n-inline-message margin-top-24 sample-test-case-notification n-info-message"><span class="width-border"></span><div class="inline-message-content"><div class="inline-message-header"><div class="info-icon"><div class="vertical-align-middle inline-block type-icon"><i class="icon ui-exclamation-o" style="font-size: 12px;"></i></div></div><div class="inline-message-header-content"><div class="inline-message-content">The following test cases are the actual test cases of this question that may be used to evaluate your submission.</div></div><i class="empty-icon"></i></div></div></div><div class="margin-top-24"><div id="sample-test-case-20853368" class="sample-test-case margin-top-24"><div class="view-sample-test-case d-flex margin-bottom-12"><div class="padding-right-36 w-50"><div class="d-flex title-container"><div class="sample-title">Sample input 2</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 200px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">9 7 5 1 6</pre><pre style="position: absolute; left: 0px; top: 60px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 80px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5 4 1 5 1</pre><pre style="position: absolute; left: 0px; top: 100px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 120px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">6 8 1 9 5</pre><pre style="position: absolute; left: 0px; top: 140px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 160px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">10 3 10 9 5</pre><pre style="position: absolute; left: 0px; top: 180px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre></div></div></div></div></div><div class="w-50"><div class="d-flex title-container"><div class="sample-title">Sample output 2</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 120px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">3</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 60px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 80px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 100px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;"></pre></div></div></div></div></div></div><div class="view-more-text inline-block margin-bottom-12" role="presentation">View more</div><textarea class="text-area-to-copy"></textarea></div><div id="sample-test-case-20853369" class="sample-test-case margin-top-24"><div class="view-sample-test-case d-flex margin-bottom-12"><div class="padding-right-36 w-50"><div class="d-flex title-container"><div class="sample-title">Sample input 3</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 200px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5 6 2 6 1</pre><pre style="position: absolute; left: 0px; top: 60px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 80px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5 10 7 3 10</pre><pre style="position: absolute; left: 0px; top: 100px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 120px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">8 10 3 5 7</pre><pre style="position: absolute; left: 0px; top: 140px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre><pre style="position: absolute; left: 0px; top: 160px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">7 3 9 6 1</pre><pre style="position: absolute; left: 0px; top: 180px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">5</pre></div></div></div></div></div><div class="w-50"><div class="d-flex title-container"><div class="sample-title">Sample output 3</div><span class="copy-text" role="presentation">Copy</span></div><div class="margin-top-12"><div class="sample-data"><div style="position: relative; height: 220px; width: 100%; overflow: auto; will-change: transform; direction: ltr;"><div style="height: 120px; width: 100%;"><pre style="position: absolute; left: 0px; top: 0px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 20px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 40px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 60px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">2</pre><pre style="position: absolute; left: 0px; top: 80px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;">1</pre><pre style="position: absolute; left: 0px; top: 100px; height: 20px; width: 100%; padding-left: 16px; margin: 0px; white-space: pre; font-size: 12px;"></pre></div></div></div></div></div></div><div class="view-more-text inline-block margin-bottom-12" role="presentation">View more</div><textarea class="text-area-to-copy"></textarea></div></div></div></div><div class="small margin-bottom-4 margin-top-12"><span class="bold">Note: </span><span>Your code must be able to print the sample output from the provided sample input. However, your code is run against multiple hidden test cases. Therefore, your code must pass these hidden test cases to solve the problem statement.</span></div><div class="margin-top-10 light small problem-solution-limits"><div class="margin-top-4">Time Limit: 5.0 sec(s) for each input file</div><div class="margin-top-4">Memory Limit: 256 MB</div><div class="margin-top-4">Source Limit: 1024 KB</div><div class="margin-top-4">Marking Scheme: Score is assigned if any testcase passes</div><div class="margin-top-4">Allowed Languages: Bash, C, C++, C++14, C++17, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, Java 14, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, Python 3.8, Racket, Ruby, Rust, Scala, Swift-4.1, Swift, TypeScript, Visual Basic</div></div></div>





*************************************************************************


*/



#include<bits/stdc++.h>
using namespace std;

int meximise (int N, vector<int> A) {
   sort(A.begin(),A.end());
   int ms = 1;
   int ma = 1;
   for(int i = 1; i < N; i++){
       if(A[i] == A[i-1]+1) ms++;
       else{
           ms = 1;
       }
       if(ceil(log2(A[i])) == floor(log2(A[i])) && ms>1) ms--;
       if(ma<ms)ma=ms;
   }
   return ma;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        int out_;
        out_ = meximise(N, A);
        cout << out_;
        cout << "\n";
    }
}