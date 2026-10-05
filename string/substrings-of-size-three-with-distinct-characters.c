int countGoodSubstrings(char* s) {
    int count = 0;
    int n = strlen(s);     // one parameter and n is not accepted.

    for(int i=0; i<n-2; i++){
        if(s[i]!= s[i+1]&& s[i]!=s[i+2] && s[i+1]!=s[i+2]){
            count++;                // this is using brute force method.
        }
    }
    return count;
}

// using sliding window.

