let auth = require('basic-auth');
let user = require('./../modules/bd_user');

const serverSalt = "45%sAlT_";

function sha512(password, salt) {
    const hash = crypto.createHmac('sha512', salt);
    hash.update(password);
    const value = hash.digest('hex');
    return {
        salt: salt,
        passwordHash: value
    };
};

function checkAuth(req, res, next) {
    if (!req.user) return res.sendStatus(401);
    next();
}


function checkAdmin(req, res, next) {
    if (req.user.role !== 'admin') return res.sendStatus(403);
    next();
}


async function baseauth(req, res, next) {
    let credentials = auth(req);
    if (!credentials && !(await user.getUserByLoginAndPasshash(credentials.name, sha512(credentials.pass, serverSalt).passwordHash))) {
        res.status(401).send({
            "success": false,
            "error": "Login or password is false"
        });
        next();
    }
}


module.exports = {
    checkAuth,
    checkAdmin,
    baseauth
};