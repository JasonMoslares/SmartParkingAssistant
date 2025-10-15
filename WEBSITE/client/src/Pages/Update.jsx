import React, { useState, useEffect } from 'react'
import { useNavigate, useParams } from 'react-router-dom'
import { handleRead, handleUpdate } from '../API'
import { Form, Input, Typography } from 'antd'
import '../index.css';

function Update(){
    
    const {id} = useParams();
    const navigate = useNavigate();

    const [values, setValues] = useState({parking_name: ''})

    const submitLot = (e) => {
        handleUpdate(e, id, values, navigate)
    }

    useEffect(()=> {
        handleRead(id, setValues)
    }, [id])
    

    return (
        <div className='form-container'>
            <div className='lot-form'>
            <Typography.Title level={4}>Update Parking Lot</Typography.Title>
                <Form layout='vertical'>
                    <Form.Item
                        label="Parking Name"
                        name="parking_name"
                        rules={[{ required: true, message: 'Please enter the lot name' }]}>
                            <Input placeholder="Enter Name"
                                    value={values.parking_name}
                                    onChange={(e) => setValues({...values, parking_name: e.target.value })} />
                    </Form.Item>
                    <button className='editButton' onClick={submitLot}>Update</button>
                </Form>
        </div>
        </div>
    );
}


export default Update;