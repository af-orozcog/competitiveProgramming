#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct time{
	double seconds;
	double speed;
};
int main(){
	string read;
	struct time last;
	last.seconds = 0.0;
	last.speed = 0.0;
	double lastdist = 0;
	while(getline(cin,read)){
		if(read.size() > 8){
			double colasts = last.seconds;
			double colastsp = last.speed;
			string ho = "";
			ho += read[0];
			ho += read[1];
			last.seconds = stoi(ho);
			last.seconds *= 3600.0;
			string mi = "";
			mi += read[3];
			mi += read[4];
			double temp = stoi(mi);
			temp *= 60.0;
			last.seconds += temp;
			string sec = " ";
			sec += read[6];
			sec += read[7];
			last.seconds += stoi(sec);
			string spe = "";
			lastdist += (last.seconds- colasts)*colastsp;
			for(int i = 9;i < read.size();++i){
				spe += read[i];
			}
			last.speed = stoi(spe);
			last.speed /= 3600.0;
		}
		else{
			string ho = "";
			ho += read[0];
			ho += read[1];
			double sec = stoi(ho);
			sec *= 3600.0;
			string mi = "";
			mi += read[3];
			mi += read[4];
			double temp = stoi(mi);
			temp *= 60.0;
			sec += temp;
			string seco = "";
			seco += read[6];
			seco += read[7];
			sec += stoi(seco);
			double ans = (sec - last.seconds)*last.speed;
			ans += lastdist;
			cout  << read << " "<< setprecision(2) << fixed<<ans << " km\n";
		}
		//cout << lastdist << endl;
	}
	return 0;
}