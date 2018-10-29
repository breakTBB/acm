typedef __int64 ll;
typedef const __int64 cll;
ll mul_mod(ll a,ll b,cll &n){   //二进制思想  已经测试 PKU1811 
		ll ans(0),tmp((a%n+n)%n); b=(b%n+n)%n; //b%=n;
		while(b){
			if(b&1)   if((ans+=tmp)>=n) ans-=n;
			if((tmp<<=1)>=n) tmp-=n;
			b>>=1;
		}  return ans;
}
