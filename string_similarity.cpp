/*
 * Complete the function below.
 */
long stringSimilarity(string value)
{
    int i = 0;
    for(i = 0; value[i] != '\0'; ++i);
    int n = i;
    long s = n;
    
    for(int i=1; i<n; i++) {
        int j = 0, k = i, is = 0;
        while(k<n && value[j] == value[k]){
            j++, k++, is++;
        }
        s += is;
    }
    return s;
}
