#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg(400005);
vector<ll> lazy(400005);
void update(int ind,int low,int high,int l,int r,int val){
    if(low > high){
        return;
    }
    if(lazy[ind] != 0){
        seg[ind] += lazy[ind]*(high-low+1);
        
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    
    if(r < low or high < l){
        return;
    }
    
    if(low >= l and high <= r){
        seg[ind] += (high-low+1)*val;
        
        if(low != high){
            lazy[2*ind+1] += val;
            lazy[2*ind+2] += val;
        }
        return;
    }
    
    ll mid = low + (high-low)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
    
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    
}


ll query(int ind,int low,int high,int l,int r){
    
    if(r < low or high < l or low >high){
        return 0;
    }
    
    if(lazy[ind] != 0){
        seg[ind] += lazy[ind]*(high-low+1);
        
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    
    if(low >= l and high <= r){
        return seg[ind];
    }
    ll mid = low + (high-low)/2;
    ll left = query(2*ind+1,low,mid,l,r);
    ll right = query(2*ind+2,mid+1,high,l,r);
    return left + right;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        cin >> n;
        cin >> m;
        //build(0,0,n-1);
        fill(seg.begin(),seg.end(),0);
        fill(lazy.begin(),lazy.end(),0);
        while(m--){
            int q;
            cin >> q;
            if(q == 0){
                int l,r,val;
                cin >> l >> r >> val;
                l--;r--;
                update(0,0,n-1,l,r,val);
            }
            else{
                int l,r;
                cin >> l >> r;
                l--;r--;
                cout << query(0,0,n-1,l,r) << '\n';
            }
        }
        
    }
    
    
    
    
    
    
    
    
    
    return 0;
}
