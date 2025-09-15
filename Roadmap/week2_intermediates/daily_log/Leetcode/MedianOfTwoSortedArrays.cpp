#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        double mid = (nums1.size() + nums2.size() - 1) / 2.0;
        bool isDot = (nums1.size() + nums2.size()) % 2 == 0 ? true : false;
        int i = 0;
        int j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (((i + j) / 2.0) == mid)
            {
                if (isDot)
                {
                    return (nums1[i] + nums2[j]) / 2.0;
                }
                else
                {
                    return nums1[i] > nums2[j] ? nums2[j] : nums1[i];
                }
            }
            if (nums1[i] > nums2[j])
            {
                j + 1 < nums1.size() ? j++ : 0;
            }
            else if (nums2[j] > nums1[i])
            {
                i + 1 < nums2.size() ? i++ : 0;
            }
            else
            {
                if (i + 1 < nums1.size())
                    i++;
                else if (j + 1 < nums2.size())
                    j++;
            }
        }
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double mid = (nums1.size() + nums2.size() + 1) / 2.0;
        bool isDot = (nums1.size() + nums2.size()) % 2 ? true : false;
        int i = 0;
        int j = 0;
        double median = 0;
        if (nums1.back() < nums2.front())
        {
            if (isDot)
            {
                if (mid < nums1.size())
                {
                    return nums1[floor(mid) - 1] + nums1[ceil(mid) - 1];
                }
                else if (mid > nums1.size() + 1)
                {
                    return nums2[floor(mid - nums1.size()) - 1] + nums2[ceil(mid - nums1.size()) - 1];
                }
                else
                {
                    return (nums1.back() + nums2.front()) / 2.0;
                }
            }
            else
            {
                if (mid < nums1.size())
                {
                    return nums1[mid - 1];
                }
                else
                {
                    return nums2[mid - nums1.size() - 1];
                }
            }
        }
        else if (nums2.back() < nums1.front())
        {
            if (isDot)
            {
                if (mid < nums2.size())
                {
                    return nums2[floor(mid) - 1] + nums2[ceil(mid) - 1];
                }
                else if (mid > nums2.size() + 1)
                {
                    return nums1[floor(mid - nums2.size()) - 1] + nums1[ceil(mid - nums2.size()) - 1];
                }
                else
                {
                    return (nums2.back() + nums1.front()) / 2.0;
                }
            }
            else
            {
                if (mid < nums2.size())
                {
                    return nums2[mid - 1];
                }
                else
                {
                    return nums1[mid - nums2.size() - 1];
                }
            }
        }
        else
        {
            while (i < nums1.size() || j < nums2.size())
            {
                if (nums1[i] > nums2[j])
                {
                    j++;
                }
                else
                {
                    i++;
                }
                if (((i + j + 3) / 2.0) == mid)
                {
                    if (isDot)
                    {
                        return (nums1[i] + nums2[j]) / 2.0;
                    }
                    else
                    {
                        return nums1[i] > nums2[j] ? nums2[j] : nums1[i];
                    }
                }
            }
        }
    }
};