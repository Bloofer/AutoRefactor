### AutoRefactor  

AutoRefactor is a tool which uses [Deckard](https://github.com/skyhover/Deckard) as a front-end to automatically refactor duplicates found in JAVA projects.

Please read the instructions below to use.

#### 1. Usage

##### 1.1 Build

```
$ git clone https://github.com/Bloofer/AutoRefactor.git
$ make all
```

##### 1.2 Detect Clone (Use Deckard Alarms)

**Alarm file format**
```
[Number of Clones]  
[Filename (including absolute path) of clone#1 from to]  
[Filename (including absolute path) of clone#2 from to]  
```

##### 1.3 Run AutoRefactor
```
$ ./autorefactor OPTIONS ALARMFILE [DOTFILE]
// OPTIONS : -a/-r/-c[3]
// ALARMFILE : Please read 1.2 and follow the format strictly
// DOTFILE : .dot file (CallGraph) from your project repository
```

#### 2. AutoRefactor Structure

**All directories/files in AutoRefactor**
```
└── AutoRefactor
    ├── include             // headers
    ├── dtl                 // diff library
    ├── demo                // demos you can try
    │   ├── t1
    │   ├── t2
    │   └── t3
    ├── autorefactor.cpp    // main program of AutoRefactor
    ├── fileioutil.cpp      // file io utility
    ├── ptree.cc            
    ├── treeutil.cpp        // for tree manipulation
    └── Makefile
```

#### 3. Restrictions

* Two input clones should be formatted before process
  * Use JAVA code formatter before running AutoRefactor

* Use output from Deckard code clone detector
  * Config : MIN_TOKENS='200', STRIDE='50', SIMILARITY='1'(To find 100% structural clone)

* Function-level clone alarm must be tight for AutoRefactor
  * Adjust alarm format, 'from'/'to', tightly(to fit in function bracket opener/closer) to run properly 

#### 4. Trouble Shooting

Please [email](mailto:jmyang@ropas.snu.ac.kr) me or write a github issue if you have any trouble using AutoRefactor.