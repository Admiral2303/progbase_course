let read = require('read');


function readConsole(dataType, defaultValue) {
    return new Promise((resolve, reject) => {
      read({
        prompt: dataType + ": ",
        default: defaultValue
      }, (error, result) => {
      if (error) reject(error);
      else resolve(result);
      });
    });
  };
  
  
  module.exports = {
      readConsole
  };