#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
class Cricket {
private:
    int currentTeam = 1;
    int striker = 1;      
    int non_striker = 2;  
    int bowler = 1;      
    int total_balls = 0; 
    int total_overs = 0;  
    bool wideBall = false;  
    bool noBall = false;    

    string team1_name = "", team2_name = "";  
    vector <pair<string, string>> team1, team2;  
    int team1_runs = 0, team2_runs = 0, team1_wickets = 0, team2_wickets = 0, team1_balls = 0, team2_balls = 0;
    
    vector <vector<int> > totalScore1, totalScore2; 
    
    map<pair<string, string>, map<string, int>> team1_stats, team2_stats; 

public:
    int num;
    bool matchEnd = false;
    int winner = 0;    
    void setTeam(int team_number, string team_name, vector <pair<string, string>> team)
    {
        if (team_number == 1)
        {
            team1_name = team_name;
            for (auto i : team)
                team1.push_back(i);
        }
        else
        {
            team2_name = team_name;
            for (auto i : team)
                team2.push_back(i);
        }
    }
    void setBowler(int player)
    {
        bowler = player;
    }

   
    void setWideBall(bool value)
    {
        wideBall = value;
    }
    void setNoBall(bool value)
    {
        noBall = value;
    }

    bool teamsEntered()
    {
        return team1_name != "" && team2_name != "";
    }
    int getBalls()
    {
        return total_balls;
    }
    int getWickets(int team)
    {
        if (team == 1)
            return team1_wickets;
        return team2_wickets;
    }
    int getTeamSize()
    {
        return team1.size();
    }

    void showCurrentBatters(int team)
    {
        if (team == 1)
        {
            cout << "Striker = " << team1[striker - 1].first << " " << team1[striker - 1].second;
            cout << endl;
            cout << "Non-Striker = " << team1[non_striker - 1].first << " " << team1[non_striker - 1].second << endl;
        }
        else
        {
            cout << "Striker = " << team2[striker - 1].first << " " << team2[striker - 1].second;
            cout << endl;
            cout << "Non-Striker = " << team2[non_striker - 1].first << " " << team2[non_striker - 1].second << endl;
        }
    }
    void updateWickets(int team)
    {
        if (team == 1)
            team1_wickets++;
        else
            team2_wickets++;
    }
    void changeBatsman()
    {
        striker = max(striker, non_striker) + 1;
    }
  
    void strikeChange()
    {
        int temp = striker;
        striker = non_striker;
        non_striker = temp;
    }
    int getStriker() {
        return striker;
    }
    int getNonStriker() {
        return non_striker;
    }
    int getBowler() {
        return bowler;
    }
 
    int getBattingTeam()
    {
        return currentTeam;
    }
    void increaseBalls() {
        total_balls++;
        if (total_balls % 6 == 0) {
            total_overs++;
        }
    }
    int getRuns(int team_number)
    {
        if(team_number == 1)
            return team1_runs;
        else
            return team2_runs;

    }

 
    void showScore()
    {
        cout << left << setw(4) << setfill(separator) << team1_name << ": " << team1_runs << "/" << team1_wickets << endl;
        cout << left << setw(4) << setfill(separator) <<  team2_name << ": " << team2_runs << "/" << team2_wickets << endl;
    }

 
    void showTeam(int team)
    {
        if(team == 1)
        {
            for (int i = 1; i <= team1.size(); i++)
                cout << i << ": "<< team1[i - 1].first << " " << team1[i - 1].second <<endl;
        }
        else
        {
            for (int i = 1; i <= team2.size(); i++)
                cout << i << ": "<< team2[i - 1].first << " " << team2[i - 1].second <<endl;
        }
    }
    

    void updateStats(int runs,int wicket,int wide,int noBall)
    {
        pair <string, string> currentBatsman, currentBowler;
        if (getBattingTeam() == 1)
        {
            currentBatsman = {team1[striker - 1].first, team1[striker-1].second};
            currentBowler = {team2[bowler - 1].first, team2[bowler-1].second};

            team1_stats[currentBatsman]["RUNS"] += runs;
            if (runs == 4)
                team1_stats[currentBatsman]["FOURS"]++;
            else if (runs == 6)
                team1_stats[currentBatsman]["SIXES"]++;
            if(wide==0 && noBall==0)
            team1_stats[currentBatsman]["BALLS"]++;
            if(noBall==0 &&wide==0)
                team2_stats[currentBowler]["BALLS_BOWLED"]++;
            team2_stats[currentBowler]["RUNS_GIVEN"]+= runs + noBall+wide;
            team2_stats[currentBowler]["WICKETS"] += wicket;
        }
        else
        {
            currentBatsman = {team2[striker - 1].first, team2[striker-1].second};
            currentBowler = {team1[bowler - 1].first, team1[bowler-1].second};
            team2_stats[currentBatsman]["RUNS"] += runs;
            if (runs == 4)
                team2_stats[currentBatsman]["FOURS"]++;
            else if (runs == 6)
                team2_stats[currentBatsman]["SIXES"]++;
            team1_stats[currentBatsman]["BALLS"]++;
            if(noBall==0)
                team1_stats[currentBowler]["BALLS_BOWLED"]++;
            team1_stats[currentBowler]["RUNS_GIVEN"]+= runs + noBall;
            team1_stats[currentBowler]["WICKETS"] += wicket;

        }

    }

 
    void showStats(int team_number)
    {
     
        if (team_number == 1)
        {
            cout <<"\nBatting stats:\n";
            cout << "Player           Runs Balls Fours Sixes\n";
           
            for (int i = 0; i < team1.size(); i++)
            {
              
                pair<string, string> player = {team1[i].first, team1[i].second};

                cout << left << setw(nameWidth) << setfill(separator) <<team1[i].first << " ";
                cout << left << setw(nameWidth) << setfill(separator) <<team1[i].second << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team1_stats[player]["RUNS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team1_stats[player]["BALLS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team1_stats[player]["FOURS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team1_stats[player]["SIXES"] << " ";
                cout<<endl;
            }
      
            cout <<"\nBowling stats:\n";
            cout << "Player           Balls Wickets Runs\n";
            for (int i = 0; i < team2.size(); i++)
            {
         
                pair<string, string> bowler = {team2[i].first, team2[i].second};
           
                cout << left << setw(nameWidth) << setfill(separator) << team2[i].first << " ";
                cout << left << setw(nameWidth) << setfill(separator) <<team2[i].second << " ";
                cout << setw(numWidth) << setfill(separator) << team2_stats[bowler]["BALLS_BOWLED"] << " ";
                cout << setw(numWidth) << setfill(separator) << team2_stats[bowler]["WICKETS"] << " ";
                cout << setw(numWidth) << setfill(separator) << team2_stats[bowler]["RUNS_GIVEN"] << " ";
                cout<<endl;
            }

        }
 
        else
        {
            cout <<"\nBatting stats:\n";
            cout << "Player           Runs Balls Fours Sixes\n";
      
            for (int i = 0; i < team2.size(); i++)
            {
            
                pair<string, string> player = {team2[i].first, team2[i].second};

                cout << left << setw(nameWidth) << setfill(separator) <<team2[i].first << " ";
                cout << left << setw(nameWidth) << setfill(separator) <<team2[i].second << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team2_stats[player]["RUNS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team2_stats[player]["BALLS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team2_stats[player]["FOURS"] << " ";
                cout << left << setw(numWidth) << setfill(separator) <<team2_stats[player]["SIXES"] << " ";
                cout<<endl;
            }
        
            cout <<"\nBowling stats:\n";
            cout << "Player           Balls Wickets Runs\n";
            for (int i = 0; i < team1.size(); i++)
            {
      
                pair<string, string> bowler = {team1[i].first, team1[i].second};

             
                cout << left << setw(nameWidth) << setfill(separator) << team1[i].first << " ";
                cout << left << setw(nameWidth) << setfill(separator) <<team1[i].second << " ";
                cout << setw(numWidth) << setfill(separator) << team1_stats[bowler]["BALLS_BOWLED"] << " ";
                cout << setw(numWidth) << setfill(separator) << team1_stats[bowler]["WICKETS"] << " ";
                cout << setw(numWidth) << setfill(separator) << team1_stats[bowler]["RUNS_GIVEN"] << " ";
                cout<<endl;
            }
        }
    }

    
    void changeInnings()
    {
        cout << "INNINGS OVER\n" << endl;
        currentTeam = 2;
        striker = 1;
        non_striker = 2;
        total_balls = 0;
        total_overs = 0;
        wideBall = false, noBall = false;
    }

    void addRuns(int runs, int team_no)
    {
        if (team_no == 1)
            team1_runs += runs;
        else
            team2_runs += runs;
    }

    
    void putScore(vector <int>& v) {
        if (getBattingTeam() == 1)
            totalScore1.push_back(v);
        else
            totalScore2.push_back(v);
    }
  
    void outFile()
    {
        ofstream myfile ("data.txt");
        if (myfile.is_open())
        {
            myfile <<team1_name <<" V/S " << team2_name <<endl;

         
            myfile <<team1_name <<":\n";
            for(auto i = 0; i < num; ++i)
                myfile << i+1 <<". "<< team1[i].first << " " << team1[i].second <<endl;
            myfile << endl;

        
            myfile <<team2_name <<":\n";
            for(auto i = 0; i < num; ++i)
                myfile << i+1 <<". " << team2[i].first << " " << team2[i].second <<endl;
            
            
            myfile << "-----------------Team1--------------\n\n";
            myfile << "(playerNumber, Runs, Bowler, Out or not, type of ball)\n";
            for(auto i = totalScore1.begin(); i != totalScore1.end(); ++i)
            {
                for(auto j = (*i).begin(); j != (*i).end(); ++j)
                    myfile << *j << " ";
                myfile << endl;
            }
            cout << endl;

           
            myfile << "-----------------Team2--------------\n\n";
            myfile << "(playerNumber, Runs, Bowler, Out or not, type of ball)\n";
            for(auto i = totalScore2.begin(); i != totalScore2.end(); ++i)
            {
                for(auto j = (*i).begin(); j != (*i).end(); ++j)
                    myfile << *j << " ";
                myfile << endl;
            }

            myfile.close();
        }
        else
            cout << "Unable to open file\n";
    }

    
    const char separator = ' ';
    const int nameWidth = 8;
    const int numWidth = 5;
    
    void endMatch() {
        matchEnd = true;
        if (team1_runs == team2_runs) {
            winner = 0; 
            cout<<"match tie.";
        } else if (team1_runs > team2_runs) {
            winner = 1; 
            cout<<team1_name<<" Won the Match.";
        } else {
            winner = 2;
            cout<<team2_name<<" Won the Match.\n";
        }
    }
    
     int getMatchWinner() {
        return winner;
    }

};



void createDatabase(Cricket &match)
{
   
    int noOfPlayers;
    cout << "Enter the number of players: ";
    cin >> noOfPlayers;
    match.num = noOfPlayers;

    
    string team1_name, team2_name;
    cout << "Enter first batting team name: ";
    cin >> team1_name;
    vector <pair<string, string>> team1, team2;
    cout << "Enter Players according to the Batting Order:\n";
    
   
    for (int i = 1; i <= match.num; ++i)
    {
        cout << "Player " << i << " (FIRSTNAME LASTNAME) " << ": ";
        string fn, ln;
        cin >> fn >> ln;
        pair<string, string> player;
        player = make_pair(fn, ln);
        team1.push_back(player);
    }
    cout << endl;
    
    cout << "Enter Second team name: ";
    cin >> team2_name;
    cout << "Enter Players according to the Batting Order:\n";
    for (int i = 1; i <= match.num; ++i)
    {
        cout << "Player " << i << " (FirstName LastName) " << ": ";
        string fn, ln;
        cin >> fn >> ln;
        pair<string, string> player;
        player = make_pair(fn, ln);
        team2.push_back(player);
    }

  
    match.setTeam(1, team1_name, team1);
    match.setTeam(2, team2_name, team2);

}


bool updateScore(Cricket &match)
{
  
    if(match.matchEnd == true)
    {
        cout << "Can't update score, match is finished\n";
        return false;
    }

  
    if( ( match.getBalls() )%6 == 0)
    {
        cout << "Select bowler:\n";
        if(match.getBattingTeam() == 1)
            match.showTeam(2);
        else
            match.showTeam(1);
        int res;
        cin >> res;
        match.setBowler(res);
    }

    int wide = 0, noball = 0; 
  
    cout << "Enter Type of Ball\n";
    cout << "1 : Normal Ball\n";
    cout << "2 : Wide ball\n";
    cout << "3 : No ball\n";
    int response;
        cin >> response;
    if(response == 2) 
    {
        wide++;
        match.setWideBall(true);
    }
    else if(response == 3) 
    {
        noball++;
        match.setNoBall(true);
    }
    else
    {
        match.setWideBall(false);
        match.setNoBall(false);
    }


    cout << "Enter runs scored in this ball: "; 
    int runs;
    cin >> runs;
    cout << "Was is a wicket?(Y/N) ";
    string input;
    cin >> input;


    
    vector<int> v;

    v.push_back(match.getStriker()); 
    v.push_back(runs);
    v.push_back(match.getBowler()); 
    if(input == "y" || input == "Y")
        v.push_back(1); 
    else
        v.push_back(0); 
    v.push_back(response); 
    match.putScore(v);

 
    if (input == "Y" || input =="y")
    {
        match.updateStats(runs,1,wide,noball);
        match.changeBatsman();
        match.updateWickets(match.getBattingTeam());
        if (match.getTeamSize() == match.getWickets(match.getBattingTeam()))
            match.changeInnings();
        if(!(wide || noball))
            match.increaseBalls();
    }
    else
    {
        match.updateStats(runs, 0,wide,noball);
        if(!(wide || noball))
            match.increaseBalls();
        if (runs == 1 || runs == 3 || runs == 5)
            match.strikeChange();
    }
  
    int extra = 0;
    if(wide || noball)
        extra++;
    match.addRuns(runs + extra, match.getBattingTeam());


    if((match.getBattingTeam() == 2) && (match.getRuns(2) > match.getRuns(1))) 
    {
        match.winner = 2;
        match.matchEnd = true;
    }

    if((match.getBattingTeam() == 2) && (match.getWickets(2) == (match.num - 1) ))
    {
    
        match.winner = 1;
        match.matchEnd = true;
    }
    return 1; 
}


void choices()
{
    cout << "Enter one of the following choices:\n";
    cout << "1: Create Match:\n";
    cout << "2: Update Score\n";
    cout << "3: View Stats\n";
    cout << "4: Change Innings\n";
    cout << "5: End Match\n";
    cout << "6: Export stats\n";
   cout<<endl;
}


int main()
{
  

    Cricket match;        
  
    int option = -1;   
    bool matchGoingOn = 0;
    while (option != 5)
    {
        if (matchGoingOn)
        {
            cout << endl;      
            match.showScore();
            match.showCurrentBatters(match.getBattingTeam());
            cout << endl;
        }
          int winner =0;
        choices();   
        
        cin >> option;
        switch (option)
        {

        case 1:        
            if (matchGoingOn)
            {
                cout << "Match is already going on...\n";
                cout << "First End this Match, to create another match.\n\n";
            }
            else
            {
                createDatabase(match);
                matchGoingOn = 1;
            }
            break;

        case 2:         
            if(matchGoingOn == false)
            {
                cout <<"First create Match..\n";
                break;
            }
            updateScore(match);
            break;

        case 3:       
            cout << "1: First Innings stats\n";
            cout << "2: Second Innings stats\n";
            int input;
            cin >> input;
            if (input == 1)
                match.showStats(1);
            else
                match.showStats(2);
            break;

        case 4:           
            match.changeInnings();
            break;

        case 5:         
            match.endMatch();
                 winner = match.getMatchWinner();
                if (winner == 0) {
                
                } else {
                }
                cout << "Exiting...\n";
                option = 5; 
                break;
            
        case 6:       
            match.outFile();
            cout << "Stats stored in data.txt\n";
            break;

        default:         
            cout << "Invalid entry.\n";
            cin.clear();      
            cin.ignore(1, '\n'); 
            break;
        }
    }
 return 0;

}