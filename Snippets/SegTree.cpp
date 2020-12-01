const int max_n = 1e5 + 5;
int n;

struct segTree
{
    struct node
    {
        long long sum, add;
    };
    struct node seg[max_n + 5];
    int arr[max_n];

    void scanArr()
    {
        for(int i = 0;i < n;++i)
            scanf("%d", &arr[i]);
    }

    void build(int low = 1, int high = n, int idx = 1)
    {
        seg[idx].add = 0;
        if(low == high)
            seg[idx].sum = arr[low];
        else
        {
            int mid = low + (high - low) / 2;
            int l_idx = idx * 2, r_idx = l_idx + 1;
            build(low, mid, l_idx);
            build(mid + 1, high, r_idx);
            seg[idx].sum = seg[l_idx].sum + seg[r_idx].sum;
        }
    }
    
    void idk(int idx, int left, int right)
    {
        int l_idx = idx * 2, r_idx = l_idx + 1;
        seg[idx].sum += seg[idx].add * (right - left + 1);
        if(left != right)
        {
            seg[l_idx].add += seg[idx].add;
            seg[r_idx].add += seg[idx].add;
        }
        seg[idx].add = 0;
    }
    
    void update(int left, int right, int val, int low = 1, int high = n, int idx = 1)
    {
        idk(idx, low, high);
        if(left > high || right < low)
            return;
        if(left <= low && high <= right)
        {
            seg[idx].add += val;
            idk(idx, low, high);
        }
        else
        {
            int mid = low + (high - low) / 2;
            int l_idx = idx * 2, r_idx = l_idx + 1;
            update(left, right, val, low, mid, l_idx);
            update(left, right, val, mid + 1, high, r_idx);
            seg[idx].sum = seg[l_idx].sum + seg[r_idx].sum;
        }
    }
    
    long long query(int left, int right, int low = 1, int high = n, int idx = 1)
    {
        idk(idx, low, high);
        if(left > high || right < low)
            return 0;
        if(left <= low && high <= right)
            return seg[idx].sum;
        
        int mid = low + (high - low) / 2;
        int l_idx = idx * 2, r_idx = l_idx + 1;
        long long resA, resB;
        resA = query(left, right, low, mid, l_idx);
        resB = query(left, right, mid + 1, high, r_idx);
        return resA + resB;
    }
};
