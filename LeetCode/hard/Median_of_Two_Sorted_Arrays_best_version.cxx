class Solution {
    
//     double bin_search(vector<int>& nums1, vector<int>& nums2, int l, int r)
//     {
//         int N = nums1.size() + nums2.size();
//         if (l > r)
//         {
//             if (N % 2 == 1)
//                 return nums2[N/2];
//             else
//                 return 0.5*(static_cast<double>(nums2[N/2-1])+static_cast<double>(nums2[N/2]));
                
//         }
//          std::cout << l << " " << r << "\n";
//         int m = (l+r)/2;
//         std::cout << "m=  " << m << "\n";
        
//         int k = N/2-(m+1);
//          std::cout << "k=  " << k << "\n";
//         int largest=std::numeric_limits<int>::min();
//         if (k && k-1 < nums2.size())
//             largest = nums2[k-1];
//         largest = std::max(largest, nums1[m]);
        
//         int smallest=std::numeric_limits<int>::max();
//         if (k < nums2.size())
//             smallest = nums2[k];
//         if (m+1 < nums1.size())
//             smallest = std::min(smallest, nums1[m+1]);
//          std::cout << "largest = " << largest <<"\n";
//          std::cout << "smallest = " << smallest <<"\n";
//         if (largest <= smallest)
//         {
//             //good
//             if (N%2 == 0)
//                 return (static_cast<double>(smallest) + static_cast<double>(largest))/2;
//             else
//                 return smallest;
//         }
//         else
//         {
//             // not good
//              std::cout << "not good " << nums1[m] << " " << nums2[k] << "\n";
//             if (nums1[m] > nums2[k])
//             {
//                 return bin_search(nums1, nums2, l, m-1);
//             }
//             else
//             {
//                 return bin_search(nums1, nums2, m+1, r);
//             }
//         }
        
//     }
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int N = A.size() + B.size();
        if (B.size() < A.size())
        {
            std::swap(A, B);
        }
            
        int l = 0, r = A.size()-1;
        while (1)
        {
            // be carefull here in C++ -1/2 => 0 (we want -1)
            int i = std::floor(static_cast<double>(l)+static_cast<double>(r-l)/2);
            int j = N/2-(i+1)-1;
            // std::cout << "lr " << l << " " << r << "\n";
            // std::cout << "ij " << i << " " << j << "\n";
            
            int A1 = std::numeric_limits<int>::min();
            if (i >= 0 && i < A.size()) A1 = A[i];
            int A2 = std::numeric_limits<int>::max();
            if (i+1 < A.size()) A2 = A[i+1];
            
            int B1 = std::numeric_limits<int>::min();
            if (j >= 0 && j < B.size()) B1 = B[j];
            int B2 = std::numeric_limits<int>::max();
            if (j+1 < B.size()) B2 = B[j+1];
            
            // std::cout << "A1A2 " << A1 << " || " << A2 << "\n";
            // std::cout << "B1B2 " << B1 << " || " << B2 << "\n";
            if (A1 <= B2 && B1 <= A2)
            {
                // good
                if (N % 2 == 1)
                {
                    return std::min(A2, B2);
                }
                else
                {
                    return (static_cast<double>(std::max(A1, B1) + std::min(A2, B2))) * 0.5;
                }
            }
            else
            {
                if (A1 > B2)
                {
                    r = i-1;
                }
                else
                {
                    l = i+1;
                }
            }
        }
    }
};
