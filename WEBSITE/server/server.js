import express from "express"
import mysql from 'mysql'
import cors from 'cors'

const app = express();
app.use(express.json())
app.use(cors());

const db = mysql.createConnection({
    host: "localhost",
    port: "3307",
    user: "root",
    password: "Mysql-6045",
    database: "parking"

})

app.get('/', (req, res) => {
    const sql = "SELECT * FROM photosensor";
    db.query(sql, (err, result) => {
        if(err) return res.json({Message: "Error inside server"});
        return res.json(result);
    })
})

app.post('/photosensor', (req, res)=> {
    const sql = "INSERT INTO photosensor (`parking_name`) VALUES (?)";
    const values = [
        req.body.parking_name
    ]
    db.query(sql, [values], (err, result) => {
        if(err) return res.json(err);
        return res.json(result)
    })
})

app.get('/read/:id', (req, res) => {
    const sql = "SELECT * FROM photosensor WHERE id = ?";
    const id = req.params.id;
    db.query(sql, [id], (err, result) => {
        if(err) return res.json({Message: "Error inside server"});
        return res.json(result);
    })
})

app.put('/update/:id', (req, res) => {
    const sql = "UPDATE photosensor SET `parking_name` = ?, `status` = ? WHERE id = ?";
    const id = req.params.id;
    db.query(sql, [req.body.parking_name, req.body.status, id], (err, result) => {
        if(err) return res.json({Message: "Error inside server"});
        return res.json(result);
    })
})

app.delete('/delete/:id', (req, res) => {
    const sql = "DELETE FROM photosensor WHERE ID = ?";
    const id = req.params.id;
    db.query(sql, [id], (err, result) => {
        if(err) return res.json({Message: "Error inside server"});
        return res.json(result);
    })
})

app.listen(3001, ()=> {
    console.log("Listening");
})