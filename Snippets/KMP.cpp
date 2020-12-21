vector<int> lps;
void precompute(string a)
{
    int n = a.size();
    lps = vector<int>(n, 0);
    int len = 0, idx = 1;
    while(idx < n){
        if(a[idx] == a[len])
        {
            ++len;
            lps[idx] = len;
            ++idx;
        }
        else
        {
            if(len != 0)
                len = lps[len - 1];
            else
                lps[idx] = 0, ++idx;
        }
    }
}

bool match(string inp, string a)
{
    int n = inp.size(), m = a.size();
    int i = 0, j = 0;
    while(i < n){
        if(inp[i] == a[j])
            ++i, ++j;
        if(j == m)
            return true;
        else if(i < n && inp[i] != a[j])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }

    return false;
}
