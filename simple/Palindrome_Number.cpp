class Solution1 {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
    //将该数倒过来
		int t = x, ans = 0;
		while (t) {
			ans = ans * 10 + t % 10;
			t /= 10;
		}
		return x == ans;
	}
};
class Solution2 {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		int y = x,p=1,t;
		while (y>=10)
		{
			y /= 10;
			p *= 10;
		}
		t = x / p;
		while(x&&p>0)
		{
			if (p > x)
				t = 0;
			else
				t = x / p;
			if (t != x % 10)
				return false;
			x = x % p;
			x /= 10;
			p /= 100;
		}
		return true;
	}
};
