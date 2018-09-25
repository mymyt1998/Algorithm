static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
	string longestPalindrome(string s) {
		int i, len = s.length(), max = 1, j,x,y,p=0;
		if (len <=1)
			return s;
		for (i = 1; i < len; i++)// cacd
		{
			x = 1;//对称位置
			y = 1;//回文串长度
			while ((i+x)<len&&(i-x)>=0&&s[i + x] == s[i - x])
			{
				x++;
				y += 2;
			}
			if (y > max)
			{
				p = i - x + 1;
				max = y;
			}
			if (s[i - 1] == s[i])
			{
				x = 1;
				y = 2;
				while((i-1-x)>=0&&(i+x)<len&&s[i-1-x]==s[i+x])
				{
					x++; y += 2;
				}
				if (y > max)
				{
					p = i - x;
					max = y;
				}
			}
		}
		return s.substr(p, max);
	}
};
