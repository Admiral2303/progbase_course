const passport = require('passport')

module.exports = function(req, res, next) {
    passport.authenticate('jwt', function(err, user) {
        if (err || !user || user.role != 'admin') {
            res.send({ error: "Forbidden", errorcode: '403' })

        } else {
            req.user = user;
            next()
        }
    })(req, res, next)
}