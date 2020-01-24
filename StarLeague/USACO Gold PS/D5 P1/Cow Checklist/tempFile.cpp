            for(int k = 0; k < 2; k++) 
            {
                if(k == 0 && i == 0) 
                    continue;
                if(k == 1 && j == 0) 
                    continue;
            
                pii source = ( k == 0 ? h[i - 1] : gu[j - 1]]);
                if(i < n) 
                    dp[i+1][j][0] = Math.min(dp[i+1][j][0], dp[i][j][k] + cost(ho[i], source));
                if(j < m) 
                    dp[i][j+1][1] = Math.min(dp[i][j+1][1], dp[i][j][k] + source.dist(gu[j], source));
            }