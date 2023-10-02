//using string + simulation
vector<string> fullJustify(vector<string>& words, int max_width) {
        int n = words.size();
        vector<string>res;
        int i=0;
        while(i<n){
            int start =i;
            int total_characters =0;
            int count_words =0;
            while(i<n && total_characters + count_words + words[i].size()<=max_width){
                total_characters +=words[i].size();
                count_words++;
                i++;
            }

            int total_spaces = max_width - total_characters;
            if(count_words==1){
                string temp_res ="";
                temp_res +=words[start];
                string space(total_spaces,' ');
                temp_res+=space;
                res.push_back(temp_res);
                continue;
            }
            int equal_spaces = total_spaces/(count_words-1);
            int res_spaces = total_spaces%(count_words-1);

            vector<int>spaces(count_words-1,equal_spaces);
            int j=0;
            while(res_spaces){
                spaces[j++] +=1;
                res_spaces--;
            }

            j=0;
            string temp_res ="";
            if(i<n ){
                for(int k=start;k<i;k++){
                    temp_res +=words[k];
                    if(j<spaces.size()){
                        string space(spaces[j++],' ');
                        temp_res +=space;
                    }
                }
            }

            else{
                for(int k= start;k<i;k++){
                    temp_res+=words[k];
                    temp_res +=' ';
                    total_spaces--;
                }
                if(total_spaces<=0){
                    temp_res.pop_back();
                }
                else{
                    string space(total_spaces,' ');
                    temp_res +=space;
                }
            }
            res.push_back(temp_res);
        }
        return res;
    }