import numpy as np
import pandas as pd


def score(data, mean):
    score = 0
    for k in range(len(data)):
        score += data[k]/mean[k]
    return score


def winning_rate(score1, score2):
    return score1 / score2


teams = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/teams.txt',
        header=None))
print(teams)

team_season = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/team_season.txt',
        header=None))
# print(team_season)
# print(team_season.shape)

team_season_num = 1
player_regular_season_num = 1
player_playoffs_num = 1

while int(team_season[1][team_season_num]) < 2002:
    team_season_num += 1
# print(team_season_num)
team_season_data = np.zeros([1188-team_season_num, 33])
team_season_data = np.array(np.array(team_season)[team_season_num:1188, 3:36], np.float64)
# print(team_season_data)
# print(team_season_data.shape)
team_mean = np.mean(team_season_data, axis=0)
# print(team_mean)
team_score = np.zeros(teams.shape[0])
# print(len(team_season_data[1]))
teams_num = 0
for i in range(teams.shape[0]):
    for j in range(team_season_data.shape[0]):
        if team_season[0][j+team_season_num] == teams[0][i]:
            team_score[i] += score(team_season_data[j], team_mean)
# print(team_score.shape)
# print(teams.shape)
for i in range(teams.shape[0]):
    if team_score[i] != 0:
        teams_num += 1
# print(teams_num)
teams_wining_rate = np.zeros([teams_num, teams_num])
# print(teams_wining_rate.shape)
index1 = 0
index2 = 0
for i in range(teams.shape[0]):
    if team_score[i] != 0:
        index1 += 1
        for j in range(teams.shape[0]):
            if team_score[j] != 0:
                index2 += 1
                teams_wining_rate[index1-1, index2-1] = winning_rate(team_score[i], team_score[j])
        index2 = 0
print(teams_wining_rate)
