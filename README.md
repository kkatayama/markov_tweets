Markov Chain Generator Manual
===

##Phase 1
C++ program that reads in a text file containing sentences and produces a Markovian tweet with the style of the input text.  

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovChain.cpp|
| COMPILE |g++ -o markovChain.cpp -o markovChain|
| USAGE |./markovChain <FILE_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

Example
---
```
$ ./markovChain constitution.txt 2 16

Sentence: in going to Grant Reprieves and Pardons for Offenses against the beginning of Rebellion or other

```
<br />

Parameter Description
---
| Parameter | Description |
| --- | --- |
| FILE_NAME | Text file containing sentences |
| CHAIN_LENGTH | Size of prefix for Markov chain.| 
| SENTENCE_LENGTH | Number of words for Markov sentence generation (~16 is good for tweets)|

<br />

Phase 2
===
Script that consumes a Twitter username, captures their tweets into a textfile, and then feeds this file into our markovChain binary.

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovTweet.ipy|
| USAGE |ipython markovTweet.ipy <USER_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

Example
---
```
$ ipython markovTweet.ipy KimKardashian 2 16

Sentence: now to find out how you can help! Xo is desperately searching for anything from you

```
<br />

Tools Used
---
| Tool | Description |
| --- | --- |
| wget | 'wget "http://mytwitterid.com/api/index.php?screen_name=' + username + '" -O userid' <br />**used to retrieve the userid** |
| twurl | 'twurl \"/1.1/statuses/user_timeline.json?user_id='+str(userid)+'&screen_name='+username+'\"' <br />**used to retrieve the latest tweets and save it to a file** | 
| markvoChain | **used to generate markovian tweets :)** |

<br />

Phase 3
===
Script that comsumes a Twitter username and produces a tweet from my user account.

|  |  |
| ----------- |:------------------------------------|
| SOURCE |markovBot.ipy|
| USAGE |ipython markovBot.ipy <USER_NAME> <CHAIN_LENGTH> <SENTENCE_LENGTH>|
|  |  |

<br />

Example
---
```
$ ipython markovBot.ipy HillaryClinton 2 16
$ ipython markovBot.ipy realDonaldTrump 2 16

```

![img](https://github.com/kkatayama/project1/blob/master/trump_vs_clinton.png?raw=true)

To Tweet every 10 seconds
---
```bash
$ watch -n 10 ipython markovBot.ipy KimKardashian 2 12

Every 10.0s: ipython markovBot.ipy KimKardashian 2 12     

--2016-12-12 23:32:06--  http://mytwitterid.com/api/index.php?screen_name=KimKardashian
Resolving mytwitterid.com... 192.185.35.199
Connecting to mytwitterid.com|192.185.35.199|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: unspecified [application/json]
Saving to:  userid

     0K ...                                                    47.1M=0s

2016-12-12 23:32:15 (47.1 MB/s) -  userid  saved [3948]

]0;IPython: ss/project1Tweet posted by @teddykatayama.

Run `t delete status 808529952056418306` to delete.
['*******************************************************', '* Secure System: Project 1: Markovian-
tweets ver 0.1  *', '*********************** Authors ***********************', '* Kaoru (Teddy) Kat
ayama                              *', '* Alparslan Sari                                      *', '
* Pengcheng Zhou                                      *', '****************************************
***************', './markovChain Attempting to open tweets!', 'Reading from the file:', '| guys | M
eet | my | #KimKardashianGame | character | at | the | So | Chic | Boutique | in | Downtown | LA |
for | a | surprise |  | https//tco/7fNjRJyDbT | WEEK | FACIAL | #DrDevgan | https//tco/X481K2MNne |
 https//tco/7MsFuA4noZ | to | @voguemagazine | s | Instagram | to | check | out | their | stories |
 I | did | a | takeover | getting | ready | for | the | Givenchy | show | guy | is | always | in |
my | shot | https//tco/7LC6ewaYPO | No | make | up | today | https//tco/l2WknhHoiy | Yeezy | Show |
 Room | in | Paris | is | heaven | Im | gonna | wear | no | make | up | today | to | the | Balencia
ga | show | finished | the | Amanda | Knox | doc | I | dont | think | they | did | it | I | really
| want | a | Natalie | Halloway | doc | &amp | they | need | to | solve | that | crime | So | sad |
 up | in | this | bitch | like!! | https//tco/lXIqxH5ffd | and | Kim | Take | Paris | https//tco/VX
w2P2GTvU | COUTURE | https//tco/jHxTIuHzzo | BIRTHDAY | MARIO | https//tco/YRZnYJGCtm | https//tco/
fBddFNWC4R | Squad | https//tco/AC6BtjEcmT | home | early | from | the | fashion | festivities | to
 | watch | the | Netflix | Amanda | Knox | doc | Cannot | wait | to | see | this | Anyone | see | i
t | yet | Thoughts | https//tco/jx48D5qcXq | @KimKanyeKimYeFC | Looks | #KKWxPFW | https//tco/vowY6
yFRwU | @Hayden_Williams | #KimKardashianWest | x3 | by | Hayden | Williams | https//tco/qaNfPjoNpS
 | https//tco/NqMx2fJO3q | flip | &amp | eye | roll | at | the | same | damn | time | https//tco/3R
gYR9Fn2v | https//tco/9lcvCP2m7U | Slay | https//tco/Dy8FAt9qmQ | ', ' https//tco/7fNjRJyDbT:WEEK,'
, '#DrDevgan https//tco/X481K2MNne:https//tco/7MsFuA4noZ,', '#KKWxPFW https//tco/vowY6yFRwU:@Hayden
_Williams,', '#KimKardashianGame character:at,', '#KimKardashianWest x3:by,', '&amp eye:roll,', '&a
mp they:need,', '@Hayden_Williams #KimKardashianWest:x3,', '@KimKanyeKimYeFC Looks:#KKWxPFW,', '@vo
guemagazine s:Instagram,', 'Amanda Knox:doc,doc,', 'Anyone see:it,', 'BIRTHDAY MARIO:https//tco/YRZ
nYJGCtm,', 'Balenciaga show:finished,', 'Boutique in:Downtown,', 'COUTURE https//tco/jHxTIuHzzo:BIR
THDAY,', 'Cannot wait:to,', 'Chic Boutique:in,', 'Downtown LA:for,', 'FACIAL #DrDevgan:https//tco/X
481K2MNne,', 'Givenchy show:guy,', 'Halloway doc:&amp,', 'Hayden Williams:https//tco/qaNfPjoNpS,',
'I did:a,', 'I dont:think,', 'I really:want,', 'Im gonna:wear,', 'Instagram to:check,', 'Kim Take:P
aris,', 'Knox doc:I,Cannot,', 'LA for:a,', 'Looks #KKWxPFW:https//tco/vowY6yFRwU,', 'MARIO https//t
co/YRZnYJGCtm:https//tco/fBddFNWC4R,', 'Meet my:#KimKardashianGame,', 'Natalie Halloway:doc,', 'Net
flix Amanda:Knox,', 'No make:up,', 'Paris https//tco/VXw2P2GTvU:COUTURE,', 'Paris is:heaven,', 'Roo
```

<br />

Tools Used
---
| Tool | Description |
| --- | --- |
| wget | 'wget "http://mytwitterid.com/api/index.php?screen_name=' + username + '" -O userid' <br />**used to retrieve the userid** |
| twurl | 'twurl \"/1.1/statuses/user_timeline.json?user_id='+str(userid)+'&screen_name='+username+'\"' <br />**used to retrieve the latest tweets and save it to a file** | 
| markvoChain | './markovChain tweets ' + chain_length + ' ' + sentence_length <br />**used to generate markovian tweets :)** |
| t | 't update \"' + tweet + '\"' <br />**used to post tweet using my account** |

<br />
