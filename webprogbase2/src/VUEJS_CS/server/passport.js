const passport = require('passport');

let User = require('./modules/bd_user');

const JwtStrategy = require('passport-jwt').Strategy
const ExtractJwt = require('passport-jwt').ExtractJwt

let env = require('node-env-file');
env('./config' + '/.env');

passport.use(
    new JwtStrategy({
        jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken(),
        secretOrKey: process.env.JWTSECRET
    }, async function(jwtPayload, done) {
        try {
            // console.log(jwtPayload);
            let user = await User.getUserById(jwtPayload._id); //getUserByLoginAndPasshash(jwtPayload.login, jwtPayload.password);

            if (!user) {
                return done(new Error(), false)
            }
            return done(null, user)
        } catch (err) {
            console.log(err);
            return done(new Error(), false)
        }
    })
)

module.exports = null