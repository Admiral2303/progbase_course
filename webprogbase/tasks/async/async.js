'use strict'
require('http');
const https = require('https');
function askQuestion() {
    process.stdout.write('Input city name: ');
}


function processInput(buffer) {
    let inputString = buffer.toString().trim();
    console.log(`Entered city: '${inputString}'`);
    if (inputString) {
        // @todo process city 
        // ...
        const fs = require('fs');
        fs.readFile(inputString+ ".txt", (err, data) => {
        if (err) {
          console.log("an error occured: " + err);
          let query = 'https://api.teleport.org/api/cities/?search=' + inputString;
          https.get(query, (res) => {
            res.on('data', (d) => {
              process.stdout.write(d);
              let link = JSON.parse(d)["_embedded"]["city:search-results"][0]["_links"]["city:item"].href;
              let newstring = '';
              https.get(link, (res) => {
              res.on('data', (d) => {
                newstring += d;
              });
              res.on('end', (d) => {
                console.log(JSON.parse(newstring));

                fs.writeFileSync(inputString + ".txt", inputString + "\r\n" + JSON.stringify(JSON.parse(newstring), null, 2), "ascii");
                console.log("»> Information was received from the Internet «<");
                askQuestion();
              });        
              }).on('error', (e) => {
                console.error(e);
              }); 
            });        
          }).on('error', (e) => {
              console.error(e);
          });
            //console.log(`Entered city: '${data}'`);
            }
            else{
              console.log("File:" + data);
              askQuestion();
            }
            // data is null if an error occured
        });
        //askQuestion();  // ask the question again
    } else {
        // exit
        console.log(`Exit.`);
        process.stdin.end();  // stop listening input
    }
}

process.stdin.addListener('data', processInput);
askQuestion();