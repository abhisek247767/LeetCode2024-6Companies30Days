class Bank {
public:
vector<long long> bal;
long long n;
    Bank(vector<long long>& balance) {
        for(auto b : balance){
            bal.push_back(b);
        }
        n=bal.size();
    }
    bool accValid(int ac){
        if(ac>=1 && ac<=n){
            return true;
        }
        return false;
    }
    bool transfer(int acc1, int acc2, long long money) {
          if(!accValid(acc1) ||  !accValid(acc2) || bal[acc1-1]<money   ){
            return false;
          }
          else{
            bal[acc1-1]-=money;
             bal[acc2-1]+=money;
             return true;
          }
    }
    
    bool deposit(int acc, long long money) {
        if( !accValid(acc) ){
            return false;
        }
        bal[acc-1]+=money;
        return true;
    }
    
    bool withdraw(int acc, long long money) {
        if( !accValid(acc) || bal[acc-1]<money ){
            return false;
        }
        else{
            bal[acc-1]-=money;
            return true;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */