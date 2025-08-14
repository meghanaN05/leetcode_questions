class Solution {
public:
    vector<int> temp;

    void merge(vector<int>& nums, int l, int mid, int r) {
        int left = l, right = mid + 1;
        temp.clear();

        while (left <= mid && right <= r) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= r) temp.push_back(nums[right++]);

        
        for (int i = 0; i < temp.size(); i++) {
            nums[l + i] = temp[i];
        }
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        temp.reserve(nums.size()); 
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
