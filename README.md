# Branch-Predictors
Program that reads addresses and whether it is taken or not taken from input file and writes results into a test file. 
Then runs different branch predictors:
    1. Always Taken
    2. Always Not Taken
    3. One-bit Bimodal Predictor
    4. Two-bit Bimodal Predictor
    5. Gshare Predictor
    6. Tournament Predictor (combination of Two-bit Bimodal and Gshare)
    
Output file Format:

x,y; <- Always Taken (x=number of correct predictions, y=number of branches)
x,y; <- Always NT
x,y; x,y; x,y; x,y; x,y; x,y; x,y; <- Single bit Bimodal predictors (table size 16, 32, 128, 256, 512, 1024, 2048)
x,y; x,y; x,y; x,y; x,y; x,y; x,y; <- Two bit saturating Bimodal Predictors (table size 16, 32, 128, 256, 512, 1024, 2048)
x,y; x,y; x,y; x,y; x,y; x,y; x,y; x,y; x,y; <- Gshare (table size = 2048, history length 3 - 11 bits)
x,y; <- Tournament (table size = 2048, history length = 11 bits)
