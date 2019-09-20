int stopMotion[1][11] = { //直立不動
                  {600,0,0,0,0,0,0,0,0,0,0},
                };

int goStepRight[3][11] = { //一歩前進(右足)
                  {300,0,0,800,0,0,0,0,0,0,0},
                  {300,-600,-600,800,0,0,0,0,0,0,0},
                  {300,-600,-600,0,0,0,0,0,0,0,0},
                };

int goStepLeft[3][11] = { //一歩前進(左足)
                  {300,-600,-600,-800,0,0,0,0,0,0,0},
                  {300,600,600,-800,0,0,0,0,0,0,0},
                  {300,600,600,0,0,0,0,0,0,0,0},
                };

int backStepRight[3][11] = { //一歩後退(右足)
                  {300,-600,-600,800,0,0,0,0,0,0,0},
                  {300,600,600,800,0,0,0,0,0,0,0},
                  {300,600,600,0,0,0,0,0,0,0,0},
                };
                
int backStepLeft[3][11] = { //一歩後退(左足)
                  {300,0,0,-800,0,0,0,0,0,0,0},
                  {300,-600,-600,-800,0,0,0,0,0,0,0},
                  {300,-600,-600,0,0,0,0,0,0,0,0},
                };

int turningRight45[10][11] = { //右旋回(45°)
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int turningRight90[20][11] = { //右旋回(90°)
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,-650,600,0,0,0,0,0,0,0},
                    {500,0,-650,-600,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int turningLeft45[10][11] = { //左旋回(45°)
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int turningLeft90[20][11] = { //左旋回(90°)
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    {300,0,0,-600,0,0,0,0,0,0,0},
                    {300,650,0,-600,0,0,0,0,0,0,0},
                    {500,650,0,600,0,0,0,0,0,0,0},
                    {300,0,0,600,0,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},                    
                    };                    

int waveRightHand[3][11] = { //右手を振る
                    {300,0,0,0,0,600,0,0,0,0,0},
                    {300,0,0,0,0,-600,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int waveLeftHand[3][11] = { //左手を振る
                    {300,0,0,0,0,0,600,0,0,0,0},
                    {300,0,0,0,0,0,-600,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };
                    
int waveBothHand[3][11] = { //両手を振る
                    {300,0,0,0,0,600,600,0,0,0,0},
                    {300,0,0,0,0,-600,-600,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int turnRight[2][11] = { //右を向く
                    {300,0,0,0,1000,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };

int turnLeft[2][11] = { //左を向く
                    {300,0,0,0,-1000,0,0,0,0,0,0},
                    {300,0,0,0,0,0,0,0,0,0,0},
                    };
