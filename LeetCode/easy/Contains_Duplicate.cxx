class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		std::unorder_set<int> s;
		for (auto c : nums)
			s.insert(c);
		return s.size() != nums.size();
	}
}