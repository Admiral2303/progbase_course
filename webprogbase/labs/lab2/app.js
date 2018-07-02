const book = require('./books');
var readline = require('readline');
let prompt = require('prompt-promise');
let read = require('read');
let fs = require('fs');









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


function processinput(){
console.log('Виберіть');
console.log("1. Добавити книгу");
console.log("2. Вивести всі книги");
console.log("3. Отримати книгу за індексом");
console.log("4. Обновити інформацію про книгу за індексом");
console.log("5. Видалити книгу за індексом");
let name, surname, data, year, pages;
readConsole('Value', '0')
  .then(input => {
    switch (input) {
      case '1':
          book.createBook()
            .then(obj => book.create(obj))
            .catch(error => {
              console.log('Oops, there was some error');
              })
              .then(() => {processinput()})
        break;
      case '2':
        book.getAll()
          .then((jsonArr) => {
            jsonArr.map(function (object) {
              console.log(`name: '${object.name}'`);
              console.log(`author: '${object.author}'`);
              console.log(`date: '${object.date}'`);
              console.log(`year: '${object.year}'`);
              console.log(`pages: '${object.pages}'`);
              console.log("\n");
            })
          })
          .catch(error => {
            console.log('Oops, there was some error');
            })
            .then(() => { processinput()})
        break;
      case '3':
        console.log("Введіть індекс об'єкта");
        readConsole("Index:", "")
          .then(index => {
            book.getById(index)
              .then(object => {
                console.log("\n");
                console.log(`name: '${object.name}'`);
                console.log(`author: '${object.author}'`);
                console.log(`date: '${object.date}'`);
                console.log(`year: '${object.year}'`);
                console.log(`pages: '${object.pages}'`);
                console.log("\n");
              })
              .catch(error => {
                console.log('Oops, there was some error');
                })
          })
          .catch(error => {
            console.log('Oops, there was some error');
            })
            .then(() => { processinput()});
          break;
      case '4':
        console.log("Введіть індекс елемента в якому обновити дані");
        readConsole("Index:", "")
          .then(async(index) => {
              let obj = await book.createBook();
              let x = await book.update(index, obj);
          })
          // .catch(error => {
          //   console.log('Oops, there was some error');
          //   })
            .then(() => { processinput()});
          break;
      case '5':
        console.log("Введіть індекс елемента який видалити");
        readConsole("Index:", "")
          .then(async(index) => {  
            await book.remove(index);
          })
          .catch(error => {
            console.log('Oops, there was some error');
            })
          .then(() => { processinput()});
        break;
      case '6':
          return;
          break;
      default:
        
        break;
    }
  });
  
}


  processinput();













  // readConsole('name', '')
  // .then(resolve => {
  //   name = resolve;
  //   readConsole('surname', '')
  //     .then(resolve => {
  //       surname = resolve;
  //       readConsole('data', '')
  //         .then(resolve => {
  //           data = resolve;
  //           readConsole('year', '')
  //             .then(resolve => {
  //               year = resolve;
  //               readConsole('pages', '')
  //                 .then(resolve => {
  //                   pages = resolve;
  //                   let b = book.createBook(name, surname, data, year, pages);
  //                   book.create(b);
  //                 })
  //             })
  //         })
  //     })
  // })