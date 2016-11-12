CryptoLocker Virus simplified Demo using AndrewKiluk's RSA-Library
----------------------
**This Code was produced for educational purposes any and all modifications/use of the code should be done carefully**
##Development:##
1.Modify Original library to only contain one key object type to reduce overhead. 
2.Text File Encryption with public key(can be modified to work on all data types).
3.Directory hopping encryption for a linux machine. (Only allow down search to keep contain in secured test folders)
4.Text File Decryption
5.Directory hopping decryption.

##How to Build:##
Compile:
"dtmirizzi@Deo:~/gitRepos/C-CryptoLockerResearch$ gcc -o test.out cryptoLocker.c rsa.c"
And run: 
"dtmirizzi@Deo:~/gitRepos/C-CryptoLockerResearch$ ./test.out"
