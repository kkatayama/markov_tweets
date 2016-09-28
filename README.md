#Markov Chain Generator Manual

##Phase 1
C++ program that reads in a text file containing sentences and produces a Markovian tweet with the style of the input text.  

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovChain.cpp|
| COMPILE |g++ -o markovChain.cpp -o markovChain|
| USAGE |./markovChain <FILE_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

####Example
```
./markovChain constitution.txt 2 16

Sentence: in going to Grant Reprieves and Pardons for Offenses against the beginning of Rebellion or other

```
<br />

####Parameter Description
| Parameter | Description |
| --- | --- |
| FILE_NAME | Text file containing sentences |
| CHAIN_LENGTH | Size of prefix for Markov chain.| 
| SENTENCE_LENGTH | Number of words for Markov sentence generation (~16 is good for tweets)|

<br />

##Phase 2
Script that consumes a Twitter username, captures their tweets into a textfile, and then feeds this file into our markovChain binary.

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovTweet.ipy|
| USAGE |ipython markovTweet.ipy <USER_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

####Example
```
ipython markovTweet.ipy KimKardashian 2 16

Sentence: now to find out how you can help! Xo is desperately searching for anything from you

```
<br />

####Tools Used
| Tool | Description |
| --- | --- |
| wget | 'wget "http://mytwitterid.com/api/index.php?screen_name=' + username + '" -O userid' <br />used to retrieve the userid |
| twurl | 'twurl \"/1.1/statuses/user_timeline.json?user_id='+str(userid)+'&screen_name='+username+'\"' <br />used to retrieve the latest tweets and save it to a file | 
| markvoChain | used to generate markovian tweets :) |

<br />

##Phase 3
Script that comsumes a Twitter username and produces a tweet from my user account.

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovBot.ipy|
| USAGE |ipython markovBot.ipy <USER_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

####Example
```
ipython markovBot.ipy HillaryClinton 2 16
ipython markovBot.ipy realDonaldTrump 2 16
```

![img](https://github.com/kkatayama/project1/blob/master/trump_vs_clinton.png?raw=true)

<br />

####Tools Used
| Tool | Description |
| --- | --- |
| wget | 'wget "http://mytwitterid.com/api/index.php?screen_name=' + username + '" -O userid' <br />used to retrieve the userid |
| twurl | 'twurl \"/1.1/statuses/user_timeline.json?user_id='+str(userid)+'&screen_name='+username+'\"' <br />used to retrieve the latest tweets and save it to a file | 
| markvoChain | './markovChain tweets ' + chain_length + ' ' + sentence_length <br />used to generate markovian tweets :) |
| t | 't update \"' + tweet + '\"' <br />used to post tweet using my account |

<br />
