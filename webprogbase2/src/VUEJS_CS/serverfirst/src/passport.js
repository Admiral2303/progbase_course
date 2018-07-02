const passport = require('passport');

let User = require('../models/user');

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
            let user = await User.getUserById({ id: jwtPayload.id });
            if (!user) {
                return done(new Error(), false)
            }
            return done(null, user)
        } catch (err) {
            return done(new Error(), false)
        }
    })
)

module.exports = null