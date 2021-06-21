import numpy as np
import pandas as pd
from sklearn.cluster import AgglomerativeClustering


def score(data, mean):
    score = 0
    for k in range(len(data)):
        score += data[k]/mean[k]
    return score


player_allstars = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/player_allstar.txt',
        header=None))
player_playoffs_career = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/player_playoffs_career.txt',
        header=None))
player_regular_season_career = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/player_regular_season_career.txt',
        header=None))
players = pd.DataFrame(pd.read_csv(
        'E:/Commonly used files/temp/Machine_learning/Course Project 2021/databasebasketball2.0/players.txt',
        header=None))

# print(player_allstars)
# print(player_allstars.shape)

print("result from player_playoffs_career:")
# print(player_playoffs_career)
player_playoffs_career_data = np.zeros([2055, 16])
player_playoffs_career_data = np.array(np.array(player_playoffs_career)[1:2056, 4:21], np.int64)
# print(player_playoffs_career_data)
# print(player_playoffs_career_data.shape)
player_playoffs_career_data_mean = np.mean(player_playoffs_career_data, axis=0)
# print(player_playoffs_career_data_mean)
player_playoffs_career_data_label = AgglomerativeClustering(n_clusters=10).fit_predict(player_playoffs_career_data)
# print(player_playoffs_career_data_label)
player_playoffs_career_data_score = np.zeros(10)
num_of_num1 = np.zeros(10)
for i in range(player_playoffs_career_data.shape[0]):
    if player_playoffs_career_data_label[i] == 0:
        num_of_num1[0] += 1
        player_playoffs_career_data_score[0] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 1:
        num_of_num1[1] += 1
        player_playoffs_career_data_score[1] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 2:
        num_of_num1[2] += 1
        player_playoffs_career_data_score[2] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 3:
        num_of_num1[3] += 1
        player_playoffs_career_data_score[3] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 4:
        num_of_num1[4] += 1
        player_playoffs_career_data_score[4] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 5:
        num_of_num1[5] += 1
        player_playoffs_career_data_score[5] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 6:
        num_of_num1[6] += 1
        player_playoffs_career_data_score[6] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 7:
        num_of_num1[7] += 1
        player_playoffs_career_data_score[7] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 8:
        num_of_num1[8] += 1
        player_playoffs_career_data_score[8] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
    if player_playoffs_career_data_label[i] == 9:
        num_of_num1[9] += 1
        player_playoffs_career_data_score[9] += score(player_playoffs_career_data[i], player_playoffs_career_data_mean)
player_playoffs_career_data_data_label_max = 0
player_playoffs_career_data_data_score_max = 0
for j in range(10):
    player_playoffs_career_data_score[j] = player_playoffs_career_data_score[j]/num_of_num1[j]
    if player_playoffs_career_data_data_score_max < player_playoffs_career_data_score[j]:
        player_playoffs_career_data_data_score_max = player_playoffs_career_data_score[j]
        player_playoffs_career_data_data_label_max = j
# print(player_playoffs_career_data_score)
# print(player_playoffs_career_data_data_label_max)
Best_players_list1 = []
for k in range(player_playoffs_career_data.shape[0]):
    if player_playoffs_career_data_label[k] == player_playoffs_career_data_data_label_max:
        # print("1")
        Best_players_list1.append(player_playoffs_career[1][k+1]+" "+player_playoffs_career[2][k+1])
print(Best_players_list1)

print("\n")

print("result from player_regular_season_career:")
# print(player_regular_season_career)
player_regular_season_career_data = np.zeros([3759, 18])
player_regular_season_career_data = np.array(np.array(player_regular_season_career)[1:3760, 4:20], np.int64)
player_regular_season_career_data_mean = np.mean(player_regular_season_career_data, axis=0)
# print(player_regular_season_career_data)
player_regular_season_career_data_label = AgglomerativeClustering(n_clusters=10).fit_predict(player_regular_season_career_data)
# print(player_regular_season_career_data_label)
# print(player_regular_season_career_data_label)
player_regular_season_career_data_score = np.zeros(10)
num_of_num2 = np.zeros(10)
for i in range(player_regular_season_career_data.shape[0]):
    if player_regular_season_career_data_label[i] == 0:
        num_of_num2[0] += 1
        player_regular_season_career_data_score[0] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 1:
        num_of_num2[1] += 1
        player_regular_season_career_data_score[1] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 2:
        num_of_num2[2] += 1
        player_regular_season_career_data_score[2] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 3:
        num_of_num2[3] += 1
        player_regular_season_career_data_score[3] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 4:
        num_of_num2[4] += 1
        player_regular_season_career_data_score[4] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 5:
        num_of_num2[5] += 1
        player_regular_season_career_data_score[5] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 6:
        num_of_num2[6] += 1
        player_regular_season_career_data_score[6] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 7:
        num_of_num2[7] += 1
        player_regular_season_career_data_score[7] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 8:
        num_of_num2[8] += 1
        player_regular_season_career_data_score[8] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
    if player_regular_season_career_data_label[i] == 9:
        num_of_num2[9] += 1
        player_regular_season_career_data_score[9] += score(player_regular_season_career_data[i], player_regular_season_career_data_mean)
player_regular_season_career_data_data_label_max = 0
player_regular_season_career_data_data_score_max = 0
for j in range(10):
    player_regular_season_career_data_score[j] = player_regular_season_career_data_score[j]/num_of_num2[j]
    if player_regular_season_career_data_data_score_max < player_regular_season_career_data_score[j]:
        player_regular_season_career_data_data_score_max = player_regular_season_career_data_score[j]
        player_regular_season_career_data_data_label_max = j
# print(player_regular_season_career_data_score)
# print(player_regular_season_career_data_data_label_max)
Best_players_list2 = []
for k in range(player_regular_season_career_data.shape[0]):
    if player_regular_season_career_data_label[k] == player_regular_season_career_data_data_label_max:
        # print("1")
        Best_players_list2.append(player_regular_season_career[1][k+1]+" "+player_regular_season_career[2][k+1])
print(Best_players_list2)
