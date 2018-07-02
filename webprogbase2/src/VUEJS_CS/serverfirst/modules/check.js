function checkAuth(req, res, next) {
    if (!req.user) return res.render('error', { error: "401", text: 'Unauthorized' });
    next();
}


function checkAdmin(req, res, next) {
    if (req.user.role !== 'admin') return res.render('error', { error: "403", text: 'Forbidden' });
    next();
}


module.exports = {
    checkAuth,
    checkAdmin
};