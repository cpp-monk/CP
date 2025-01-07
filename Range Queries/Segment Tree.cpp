class segmentTree
{
    private:

    vector<int> segTree;

    public:

    segmentTree(vector<int> &heights, int n)
    {
        segTree.resize(4*n);

        buildTree(heights,0,0,n-1);
    }

    void buildTree(vector<int> &heights, int idx, int start, int end)
    {
        if(start == end)
        {
            segTree[idx] = start;

            return;
        }

        int mid = (start+end)>>1;

        buildTree(heights,2*idx+1,start,mid);

        buildTree(heights,2*idx+2,mid+1,end);

        if(heights[segTree[2*idx+1]] >= heights[segTree[2*idx+2]])
        {
            segTree[idx] = segTree[2*idx+1];
        }

        else
        {
            segTree[idx] = segTree[2*idx+2];
        }
    }

    int RMIQ(vector<int> &heights, int idx, int start, int end, int l, int r)
    {
        if(start > r || end < l)
        {
            return -1;
        }

        if(start >= l && end <= r)
        {
            return segTree[idx];
        }

        int mid = (start+end)>>1;

        int left = RMIQ(heights,2*idx+1,start,mid,l,r);

        int right = RMIQ(heights,2*idx+2,mid+1,end,l,r);

        if(left == -1)
        {
            return right;
        }

        if(right == -1)
        {
            return left;
        }

        if(heights[left] >= heights[right])
        {
            return left;
        }

        else
        {
            return right;
        }
    }

    void update(int idx, int start, int end, int index, int val)
    {
        if(start == end)
        {
            segTree[idx] = val;

            return;
        }

        int mid = (start+end)>>1;

        if(index <= mid)
        {
            update(2*idx+1,start,mid,index,val);
        }

        else
        {
            update(2*idx+2,mid+1,end,index,val);
        }

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }

    int sumR(int idx, int start, int end, int left, int right)
    {
        if(start > right || end < left)
        {
            return 0;
        }

        if(start >= left && end <= right)
        {
            return segTree[idx];
        }

        int mid = (start+end)>>1;

        return sumR(2*idx+1,start,mid,left,right) + sumR(2*idx+2,mid+1,end,left,right);
    }
};
