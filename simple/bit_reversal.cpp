    static int __=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();//取消cin同步减少时间
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=0;
        for(int i=0;i<32;i++)
        {
            m<<=1;//左移补1
            m|=n&1;//m末位放入n末位
            n>>=1;//n右移
        }
        return m;
    }
};
