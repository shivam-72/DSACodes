class Solution {
public:

    void updateSeg(int i, int l, int r, int idx, vector<long long>& seg) {
        if (l == r) {
            seg[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSeg(2 * i + 1, l, mid, idx, seg);
        } else {
            updateSeg(2 * i + 2, mid + 1, r, idx, seg);
        }

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    long long querySeg(int qs, int qe, int i, int l, int r, vector<long long>& seg) {
        if (r < qs || l > qe)
            return 0;

        if (l >= qs && r <= qe)
            return seg[i];

        int mid = l + (r - l) / 2;
        long long left = querySeg(qs, qe, 2 * i + 1, l, mid, seg);
        long long right = querySeg(qs, qe, 2 * i + 2, mid + 1, r, seg);

        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> seg(4 * n);
        map<int, int> mp;

        for (int i = 0; i < n; ++i)
            mp[nums2[i]] = i;

        long long res = 0;
        updateSeg(0, 0, n - 1, mp[nums1[0]], seg);

        for (int i = 1; i < n; ++i) {
            int idx = mp[nums1[i]];
            long long leftCommon = querySeg(0, idx, 0, 0, n - 1, seg);
            long long leftNotCommon = i - leftCommon;
            long long rightTotal = (n - 1) - idx;
            long long rightCommon = rightTotal - leftNotCommon;
            res += leftCommon * rightCommon;
            updateSeg(0, 0, n - 1, idx, seg);
        }

        return res;
    }
};
